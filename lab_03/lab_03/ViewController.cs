using System;
using System.Threading;
using System.Threading.Tasks;
using System.Collections.Generic;

using AppKit;
using Foundation;

namespace lab_03
{
    public partial class ViewController : NSViewController
    {
        private Elevator elevator;

        public ViewController(IntPtr handle) : base(handle)
        {
            elevator = new Elevator();

            SetState();

            RunElevator();
            RunDoors();
        }

        private async void RunElevator()
        {
            while (true) await Task.Run(() => elevator.Run());
        }

        private async void RunDoors()
        {
            while (true) await Task.Run(() => elevator.GetDoors.Run());
        }

        private async void SetState()
        {
            while (true)
            {
                await Task.Run(() => Thread.Sleep(100));

                lblElevatorState.StringValue = elevator.State;
                lblDoorsState.StringValue = elevator.GetDoors.State;
                lblCurrentFloor.StringValue =
                    Convert.ToString(elevator.CurrentFloor + 1) + " этаж";

                List<Floor> GoFloor = elevator.GetComeToFloors;
                List<Floor> ComeFloor = elevator.GetWaitFloors;

                if (GoFloor[0].State) btnGoFloor1.Enabled = false;
                else btnGoFloor1.Enabled = true;

                if (GoFloor[1].State) btnGoFloor2.Enabled = false;
                else btnGoFloor2.Enabled = true;

                if (GoFloor[2].State) btnGoFloor3.Enabled = false;
                else btnGoFloor3.Enabled = true;

                if (GoFloor[3].State) btnGoFloor4.Enabled = false;
                else btnGoFloor4.Enabled = true;

                if (GoFloor[4].State) btnGoFloor5.Enabled = false;
                else btnGoFloor5.Enabled = true;

                if (GoFloor[5].State) btnGoFloor6.Enabled = false;
                else btnGoFloor6.Enabled = true;

                if (GoFloor[6].State) btnGoFloor7.Enabled = false;
                else btnGoFloor7.Enabled = true;

                if (GoFloor[7].State) btnGoFloor8.Enabled = false;
                else btnGoFloor8.Enabled = true;

                if (GoFloor[8].State) btnGoFloor9.Enabled = false;
                else btnGoFloor9.Enabled = true;

                if (GoFloor[9].State) btnGoFloor10.Enabled = false;
                else btnGoFloor10.Enabled = true;

                if (ComeFloor[0].State) btnCallFloor1.Enabled = false;
                else btnCallFloor1.Enabled = true;

                if (ComeFloor[1].State) btnCallFloor2.Enabled = false;
                else btnCallFloor2.Enabled = true;

                if (ComeFloor[2].State) btnCallFloor3.Enabled = false;
                else btnCallFloor3.Enabled = true;

                if (ComeFloor[3].State) btnCallFloor4.Enabled = false;
                else btnCallFloor4.Enabled = true;

                if (ComeFloor[4].State) btnCallFloor5.Enabled = false;
                else btnCallFloor5.Enabled = true;

                if (ComeFloor[5].State) btnCallFloor6.Enabled = false;
                else btnCallFloor6.Enabled = true;

                if (ComeFloor[6].State) btnCallFloor7.Enabled = false;
                else btnCallFloor7.Enabled = true;

                if (ComeFloor[7].State) btnCallFloor8.Enabled = false;
                else btnCallFloor8.Enabled = true;

                if (ComeFloor[8].State) btnCallFloor9.Enabled = false;
                else btnCallFloor9.Enabled = true;

                if (ComeFloor[9].State) btnCallFloor10.Enabled = false;
                else btnCallFloor10.Enabled = true;
            }
        }

        public override void ViewDidLoad()
        {
            base.ViewDidLoad();

            // Do any additional setup after loading the view.
        }

        public override NSObject RepresentedObject
        {
            get
            {
                return base.RepresentedObject;
            }
            set
            {
                base.RepresentedObject = value;
                // Update the view, if already loaded.
            }
        }

        partial void CallFloor1(NSObject sender)
        {
            elevator.SetWaitFloor(1);
        }

        partial void CallFloor2(NSObject sender)
        {
            elevator.SetWaitFloor(2);
        }

        partial void CallFloor3(NSObject sender)
        {
            elevator.SetWaitFloor(3);
        }

        partial void CallFloor4(NSObject sender)
        {
            elevator.SetWaitFloor(4);
        }

        partial void CallFloor5(NSObject sender)
        {
            elevator.SetWaitFloor(5);
        }

        partial void CallFloor6(NSObject sender)
        {
            elevator.SetWaitFloor(6);
        }

        partial void CallFloor7(NSObject sender)
        {
            elevator.SetWaitFloor(7);
        }

        partial void CallFloor8(NSObject sender)
        {
            elevator.SetWaitFloor(8);
        }

        partial void CallFloor9(NSObject sender)
        {
            elevator.SetWaitFloor(9);
        }

        partial void CallFloor10(NSObject sender)
        {
            elevator.SetWaitFloor(10);
        }

        partial void GoFloor1(NSObject sender)
        {
            elevator.SetComeFloor(1);
        }

        partial void GoFloor2(NSObject sender)
        {
            elevator.SetComeFloor(2);
        }

        partial void GoFloor3(NSObject sender)
        {
            elevator.SetComeFloor(3);
        }

        partial void GoFloor4(NSObject sender)
        {
            elevator.SetComeFloor(4);
        }

        partial void GoFloor5(NSObject sender)
        {
            elevator.SetComeFloor(5);
        }

        partial void GoFloor6(NSObject sender)
        {
            elevator.SetComeFloor(6);
        }

        partial void GoFloor7(NSObject sender)
        {
            elevator.SetComeFloor(7);
        }

        partial void GoFloor8(NSObject sender)
        {
            elevator.SetComeFloor(8);
        }

        partial void GoFloor9(NSObject sender)
        {
            elevator.SetComeFloor(9);
        }

        partial void GoFloor10(NSObject sender)
        {
            elevator.SetComeFloor(10);
        }
    }
}
