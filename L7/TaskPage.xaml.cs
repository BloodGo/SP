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

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

namespace SP_Lab7_UWP
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class TaskPage : Page
    {
        private double litersOn100kilometers = 0;
        private double milesOnGalon = 0;

        double squareMeters = 0;
        double squareKilometers = 0;
        double hektars = 0;
        double squareYards = 0;
        double squareMiles = 0;

        private uint wasRecalculating = 0;

        private enum FuelValueChanged
        {
            Liters,
            Miles
        }

        private enum SquareValueChanged
        {
            Meters,
            Kilometers,
            Hectars,
            Yards,
            Miles
        }

        public TaskPage()
        {
            this.InitializeComponent();
        }

        private void FuelConvertation(FuelValueChanged changedValue)
        {
            if (wasRecalculating > 0)
            {
                wasRecalculating--;
                return;
            }

            switch (changedValue)
            {
                case FuelValueChanged.Liters:
                    wasRecalculating++;
                    tbMilesToGalon.Text = string.Format("{0:0.00}", 100.0 / litersOn100kilometers * 3.785 * 0.6214);
                    break;
                case FuelValueChanged.Miles:
                    wasRecalculating++;
                    tbLitersOn100kilometers.Text = string.Format("{0:0.00}", 1.0 / milesOnGalon * 1.609 * 26.42);
                    break;
                default:
                    break;
            }
        }

        private void tbLitersOn100kilometers_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (tbLitersOn100kilometers.Text == "")
            {
                return;
            }

            if (double.TryParse(tbLitersOn100kilometers.Text, out litersOn100kilometers) == false)
            {
                tbLitersOn100kilometers.Text = "";
                return;
            }
            FuelConvertation(FuelValueChanged.Liters);
        }

        private void tbMilesToGalon_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (tbMilesToGalon.Text == "")
            {
                return;
            }

            if (double.TryParse(tbMilesToGalon.Text, out milesOnGalon) == false)
            {
                tbMilesToGalon.Text = "";
                return;
            };
            FuelConvertation(FuelValueChanged.Miles);
        }
        /// <summary>
        /// Converts squares.
        /// </summary>
        /// <param name="changedValue"></param>
        private void SquareConvertation(SquareValueChanged changedValue)
        {
            if (wasRecalculating > 0)
            {
                wasRecalculating--;
                return;
            }

            switch (changedValue)
            {
                case SquareValueChanged.Meters:                    
                    break;
                case SquareValueChanged.Kilometers:
                    squareMeters = squareKilometers * 1000000;
                    break;
                case SquareValueChanged.Hectars:
                    squareMeters = hektars * 10000;
                    break;
                case SquareValueChanged.Yards:
                    squareMeters = squareYards * 0.9144 * 0.9144;
                    break;
                case SquareValueChanged.Miles:
                    squareMeters = squareMiles * 1609.34 * 1609.34;
                    break;
                default:
                    break;
            }
            if (changedValue != SquareValueChanged.Meters)
            {
                wasRecalculating++;
                tbSquareMeters.Text = string.Format("{0:0.00}", squareMeters);
            }
            if (changedValue != SquareValueChanged.Kilometers)
            {
                wasRecalculating++;
                tbSquareKilometers.Text = string.Format("{0:0.00}", squareMeters / 1000000.0);
            }
            if (changedValue != SquareValueChanged.Hectars)
            {
                wasRecalculating++;
                tbHektars.Text = string.Format("{0:0.00}", squareMeters / 10000.0);
            }
            if (changedValue != SquareValueChanged.Yards)
            {
                wasRecalculating++;
                tbSquareYards.Text = string.Format("{0:0.00}", squareMeters / (0.9144 * 0.9144));
            }
            if (changedValue != SquareValueChanged.Miles)
            {
                wasRecalculating++;
                tbSquareMiles.Text = string.Format("{0:0.00}", squareMeters / (1609.34 * 1609.34));
            }
        }

        private void tbSquareMeters_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (tbSquareMeters.Text == "")
            {
                return;
            }

            if (double.TryParse(tbSquareMeters.Text, out squareMeters) == false)
            {
                tbSquareMeters.Text = "";
                return;
            };
            SquareConvertation(SquareValueChanged.Meters);
        }

        private void tbSquareKilometers_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (tbSquareKilometers.Text == "")
            {
                return;
            }

            if (double.TryParse(tbSquareKilometers.Text, out squareKilometers) == false)
            {
                tbSquareKilometers.Text = "";
                return;
            };
            SquareConvertation(SquareValueChanged.Kilometers);
        }

        private void tbHektars_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (tbHektars.Text == "")
            {
                return;
            }

            if (double.TryParse(tbHektars.Text, out hektars) == false)
            {
                tbHektars.Text = "";
                return;
            };
            SquareConvertation(SquareValueChanged.Hectars);
        }

        private void tbSquareYards_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (tbSquareYards.Text == "")
            {
                return;
            }

            if (double.TryParse(tbSquareYards.Text, out squareYards) == false)
            {
                tbSquareYards.Text = "";
                return;
            };
            SquareConvertation(SquareValueChanged.Yards);
        }

        private void tbSquareMiles_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (tbSquareMiles.Text == "")
            {
                return;
            }

            if (double.TryParse(tbSquareMiles.Text, out squareMiles) == false)
            {
                tbSquareMiles.Text = "";
                return;
            };
            SquareConvertation(SquareValueChanged.Miles);
        }
    }
}
