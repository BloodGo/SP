using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace SP_Lab7_UWP
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private List<MenuItem> menuItems = new List<MenuItem>();

        public MainPage()
        {
            this.InitializeComponent();

            menuItems.Add(new MenuItem { Text = "Задание по варианту", Description = "Конвертация величин" });
            menuItems.Add(new MenuItem { Text = "О программе", Description = "Информация о авторе" });

            listView.ItemsSource = menuItems;

            listView.ItemClick += ListView_ItemClick;
        }

        private void ListView_ItemClick(object sender, ItemClickEventArgs e)
        {
            switch (e.ClickedItem.ToString())
            {
                case "Задание по варианту":
                    this.contentFrame.Navigate(typeof(TaskPage));
                    break;
                case "О программе":
                    this.contentFrame.Navigate(typeof(AboutPage));
                    break;
                default:
                    break;
            }
        }
    }

    public class MenuItem
    {
        public string Text { get; set; }
        public string Description { get; set; }
        public override string ToString()
        {
            return Text;
        }
    }
}
