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
        }

        private async void SetState()
        {
            while (true)
            {
                await Task.Run(() => Thread.Sleep(100));

                lblElevatorState.StringValue = elevator.GetState;
                lblDoorsState.StringValue = elevator.Doors.GetState;
                lblCurrentFloor.StringValue =
                    Convert.ToString(elevator.CurrentFloor + 1) + " этаж";

                List<Floor> GoFloor = elevator.ComeToFloors;
                List<Floor> ComeFloor = elevator.WaitFloors;

                if (GoFloor[0].GetState) btnGoFloor1.Enabled = false;
                else btnGoFloor1.Enabled = true;

                if (GoFloor[1].GetState) btnGoFloor2.Enabled = false;
                else btnGoFloor2.Enabled = true;

                if (GoFloor[2].GetState) btnGoFloor3.Enabled = false;
                else btnGoFloor3.Enabled = true;

                if (GoFloor[3].GetState) btnGoFloor4.Enabled = false;
                else btnGoFloor4.Enabled = true;

                if (GoFloor[4].GetState) btnGoFloor5.Enabled = false;
                else btnGoFloor5.Enabled = true;

                if (GoFloor[5].GetState) btnGoFloor6.Enabled = false;
                else btnGoFloor6.Enabled = true;

                if (GoFloor[6].GetState) btnGoFloor7.Enabled = false;
                else btnGoFloor7.Enabled = true;

                if (GoFloor[7].GetState) btnGoFloor8.Enabled = false;
                else btnGoFloor8.Enabled = true;

                if (GoFloor[8].GetState) btnGoFloor9.Enabled = false;
                else btnGoFloor9.Enabled = true;

                if (GoFloor[9].GetState) btnGoFloor10.Enabled = false;
                else btnGoFloor10.Enabled = true;

                if (ComeFloor[0].GetState) btnCallFloor1.Enabled = false;
                else btnCallFloor1.Enabled = true;

                if (ComeFloor[1].GetState) btnCallFloor2.Enabled = false;
                else btnCallFloor2.Enabled = true;

                if (ComeFloor[2].GetState) btnCallFloor3.Enabled = false;
                else btnCallFloor3.Enabled = true;

                if (ComeFloor[3].GetState) btnCallFloor4.Enabled = false;
                else btnCallFloor4.Enabled = true;

                if (ComeFloor[4].GetState) btnCallFloor5.Enabled = false;
                else btnCallFloor5.Enabled = true;

                if (ComeFloor[5].GetState) btnCallFloor6.Enabled = false;
                else btnCallFloor6.Enabled = true;

                if (ComeFloor[6].GetState) btnCallFloor7.Enabled = false;
                else btnCallFloor7.Enabled = true;

                if (ComeFloor[7].GetState) btnCallFloor8.Enabled = false;
                else btnCallFloor8.Enabled = true;

                if (ComeFloor[8].GetState) btnCallFloor9.Enabled = false;
                else btnCallFloor9.Enabled = true;

                if (ComeFloor[9].GetState) btnCallFloor10.Enabled = false;
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

        private async void ACallFloor(int i)
        {
            await Task.Run(() => elevator.SetWaitFloor(i));
        }

        partial void CallFloor1(NSObject sender)
        {
            ACallFloor(1);
        }

        partial void CallFloor2(NSObject sender)
        {
            ACallFloor(2);
        }

        partial void CallFloor3(NSObject sender)
        {
            ACallFloor(3);
        }

        partial void CallFloor4(NSObject sender)
        {
            ACallFloor(4);
        }

        partial void CallFloor5(NSObject sender)
        {
            ACallFloor(5);
        }

        partial void CallFloor6(NSObject sender)
        {
            ACallFloor(6);
        }

        partial void CallFloor7(NSObject sender)
        {
            ACallFloor(7);
        }

        partial void CallFloor8(NSObject sender)
        {
            ACallFloor(8);
        }

        partial void CallFloor9(NSObject sender)
        {
            ACallFloor(9);
        }

        partial void CallFloor10(NSObject sender)
        {
            ACallFloor(10);
        }

        private async void AGoFloor(int i)
        {
            await Task.Run(() => elevator.SetComeFloor(i));
        }

        partial void GoFloor1(NSObject sender)
        {
            AGoFloor(1);
        }

        partial void GoFloor2(NSObject sender)
        {
            AGoFloor(2);
        }

        partial void GoFloor3(NSObject sender)
        {
            AGoFloor(3);
        }

        partial void GoFloor4(NSObject sender)
        {
            AGoFloor(4);
        }

        partial void GoFloor5(NSObject sender)
        {
            AGoFloor(5);
        }

        partial void GoFloor6(NSObject sender)
        {
            AGoFloor(6);
        }

        partial void GoFloor7(NSObject sender)
        {
            AGoFloor(7);
        }

        partial void GoFloor8(NSObject sender)
        {
            AGoFloor(8);
        }

        partial void GoFloor9(NSObject sender)
        {
            AGoFloor(9);
        }

        partial void GoFloor10(NSObject sender)
        {
            AGoFloor(10);
        }
    }
}
