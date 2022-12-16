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
        private string m_msg = "Empty message !";
        private string m_SileContent = string.Empty;
        private string m_FilePath = string.Empty;

        public Form1()
        {
            InitializeComponent();
        }

        private void sendFromFile(object sender, EventArgs e)
        {
            if (m_FilePath == "")
            {
                MessageBox.Show("Please load data file first !");
                return;
            }
            FileStream fs = new FileStream(m_FilePath, FileMode.Open, FileAccess.Read);
            byte[] data = new byte[fs.Length];
            fs.Read(data, 0, data.Length);
            m_UdpClient.SendTo(data, m_ServerPoint);
            m_msg = Encoding.UTF8.GetString(data);
            SendMsg.Text = m_msg;
            sendedMsg.AppendText("\r\n");
            sendedMsg.AppendText(m_msg);
            fs.Close();
        }

        ~Form1()
        {
            m_UdpClient.Close();
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
                }
            }
        }

        private void sendFromTextbox_Click(object sender, EventArgs e)
        {

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
