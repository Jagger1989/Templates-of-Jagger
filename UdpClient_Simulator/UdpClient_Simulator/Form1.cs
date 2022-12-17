using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UdpClient_Simulator
{
    public partial class Form1 : Form
    {
        private Socket m_UdpClient = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
        private EndPoint m_ServerPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 55555);
        private AutoSizeFormClass asfc = new AutoSizeFormClass();
        private string m_SileContent = string.Empty;
        private string m_FilePath = string.Empty;
        private string m_data = string.Empty;

        public Form1()
        {
            InitializeComponent();
        }

        ~Form1()
        {
            m_UdpClient.Close();
        }

        private void sendMsg(object sender, EventArgs e)
        {
            if (m_data.Length == 0)
            {
                MessageBox.Show("Message is empty !");
                return;
            }

            //MessageBox.Show(msg);

            //if (msg.Length > 1024)
            //{
            //    MessageBox.Show("Message is oversize !(" + msg.Length + " > Max 1024)");
            //    return;
            //}

            m_UdpClient.SendTo(Encoding.UTF8.GetBytes(m_data), m_ServerPoint);
            messageLog.AppendText(m_data);
            messageLog.AppendText("\r\n");
        }

        private void loadData(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.InitialDirectory = "c:\\";
                openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                openFileDialog.FilterIndex = 2;
                openFileDialog.RestoreDirectory = true;

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    //Get the path of specified file
                    m_FilePath = openFileDialog.FileName;
                    readFileToTextBox();
                }
            }
        }

        private void readFileToTextBox( )
        {
            if (!File.Exists(m_FilePath))
            {
                MessageBox.Show("File not exists !");
            }

            try
            {
                using (FileStream fs = new FileStream(m_FilePath, FileMode.Open, FileAccess.Read))
                {
                    byte[] bytes = new byte[fs.Length];
                    fs.Read(bytes, 0, bytes.Length);
                    m_data = Encoding.UTF8.GetString(bytes);
                    SendMsg.Text = m_data;
                }
            }
            catch
            {
                MessageBox.Show("Open file failed !");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            asfc.controllInitializeSize(this);
        }

        private void SendMsg_TextChanged(object sender, EventArgs e)
        {
            m_data = SendMsg.Text;
        }

        private void onClearLog(object sender, EventArgs e)
        {
            messageLog.Text = "";
        }

        private void sendMsgOnDE(object sender, DragEventArgs e)
        {
            if(e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Link;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        private void sendMsgOnDD(object sender, DragEventArgs e)
        {
            m_FilePath = ((Array)e.Data.GetData(DataFormats.FileDrop)).GetValue(0).ToString();
            readFileToTextBox();
        }

        private void onLCClick(object sender, EventArgs e)
        {
            SendMsg.Text = "";
        }

        private void onHelpClick(object sender, EventArgs e)
        {
            string msg = "step 1: Load data file or drag data file to the Command box. \r\nstep 2: Click send.";
            MessageBox.Show(msg);
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            asfc.controlAutoSize(this);
        }
    }
}
