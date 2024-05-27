using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace Coursework_WinForms {
	static class glob {
		static internal fm_main main { get; set; }
		//static internal Dictionary<string, Shape> shapes = new Dictionary<string, Shape>();
		static internal SimpleDictionary<string, Shape> shapes = new SimpleDictionary<string, Shape>();
	}

	public static class Program {
		public static bool checkFloat(params string[] args) {
			foreach (string arg in args) {
				if (!Regex.IsMatch(arg, "^\\d[\\d\\.,]*$"))
					return false;
			}
			return true;
		}

		[STAThread]
		static void Main() {
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			glob.main = new fm_main();
			Application.Run(glob.main);
		}
	}
}
