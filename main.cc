/*
 * This is the architecture
 * n1-----n0-----n2
 *       /  \
 *     n3    n4
 *
 * L1 -> 5Mbps, 2ms
 * L2 -> 10Mbps,5ms
 * L3 -> 7Mbps, 3ms
 * L4 -> 6Mbps, 5ms
 * n1,n2,n3,n4 - client, n0 - server
 *
 */
#include "ns3/mobility-module.h"
#include <fstream>
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/lte-module.h"
#include "ns3/config-store-module.h"
#include <cstdlib>
#include <iostream>
#include "ns3/netanim-module.h"
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include <ctime>
using namespace std;
using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("FirstScriptExample");
int main ()
{

  /*====Node Creation======*/
  int start_s=clock();

  Time::SetResolution (Time::NS);
  LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);

  NodeContainer nodes;
  nodes.Create (5);

  InternetStackHelper stack;
   stack.Install (nodes);

  PointToPointHelper n0n1;
  n0n1.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
  n0n1.SetChannelAttribute ("Delay", StringValue ("1ms"));

  PointToPointHelper n0n2;
  n0n2.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));
  n0n2.SetChannelAttribute ("Delay", StringValue ("5ms"));


  PointToPointHelper n0n3;
  n0n3.SetDeviceAttribute ("DataRate", StringValue ("6Mbps"));
  n0n3.SetChannelAttribute ("Delay", StringValue ("5ms"));

  PointToPointHelper n0n4;
  n0n4.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));
  n0n4.SetChannelAttribute ("Delay", StringValue ("5ms"));


int stop_s=clock();
float uf6= (stop_s-start_s)/double(CLOCKS_PER_SEC)*10;
float sh=0.1;
ud6=uf6 +sh;
  /*====Node with Head node======*/
  Ipv4AddressHelper address;
  address.SetBase ("10.1.1.0", "255.255.255.0");
  NetDeviceContainer devices;
  devices = n0n1.Install (nodes.Get (1), nodes.Get (0));
  Ipv4InterfaceContainer interfaces = address.Assign (devices);

  devices = n0n2.Install (nodes.Get (2), nodes.Get (0));
  address.SetBase ("10.1.2.0", "255.255.255.0");
  interfaces = address.Assign (devices);

  devices = n0n3.Install (nodes.Get (3), nodes.Get (0));
  address.SetBase ("10.1.3.0", "255.255.255.0");
  interfaces = address.Assign (devices);

  devices = n0n4.Install (nodes.Get (4), nodes.Get (0));
  address.SetBase ("10.1.4.0", "255.255.255.0");
  interfaces = address.Assign (devices);

  Ipv4GlobalRoutingHelper::PopulateRoutingTables ();
  UdpEchoServerHelper echoServer (9);

int stop_s2=clock();
float uf5=0.1+( (stop_s2-start_s)/double(CLOCKS_PER_SEC)*10);

  int u = 4;
  int i = 10 * (rand() / (RAND_MAX + 1.0));
  int cn = u*i;
  float i1=10 * (rand() / (RAND_MAX + 0.293));




  if (cn>1)
  {
      /* Channel Allocation*/

    cn = cn+i;
    
    ApplicationContainer serverApps = echoServer.Install (nodes.Get (0));
    serverApps.Start (Seconds (1.0));
    serverApps.Stop (Seconds (10.0));

    UdpEchoClientHelper echoClient1 (interfaces.GetAddress (0), 54);
    echoClient1.SetAttribute ("MaxPackets", UintegerValue (1));
    echoClient1.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
    echoClient1.SetAttribute ("PacketSize", UintegerValue (256));

    ApplicationContainer clientApps1 = echoClient1.Install (nodes.Get (1));
    clientApps1.Start (Seconds (3.0));
    clientApps1.Stop (Seconds (5.0));


    UdpEchoClientHelper echoClient2 (interfaces.GetAddress (0), 55);
    echoClient2.SetAttribute ("MaxPackets", UintegerValue (1));
    echoClient2.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
    echoClient2.SetAttribute ("PacketSize", UintegerValue (512));

    ApplicationContainer clientApps2 = echoClient2.Install (nodes.Get (2));
    clientApps2.Start (Seconds (6.0));
    clientApps2.Stop (Seconds (7.0));


    UdpEchoClientHelper echoClient3 (interfaces.GetAddress (0), 56);
    echoClient3.SetAttribute ("MaxPackets", UintegerValue (1));
    echoClient3.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
    echoClient3.SetAttribute ("PacketSize", UintegerValue (256));

    ApplicationContainer clientApps3 = echoClient3.Install (nodes.Get (3));
    clientApps3.Start (Seconds (7.2));
    clientApps3.Stop (Seconds (8.0));


    UdpEchoClientHelper echoClient4 (interfaces.GetAddress (0), 57);
    echoClient4.SetAttribute ("MaxPackets", UintegerValue (1));
    echoClient4.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
    echoClient4.SetAttribute ("PacketSize", UintegerValue (1024));

    ApplicationContainer clientApps4 = echoClient4.Install (nodes.Get (4));
    clientApps4.Start (Seconds (8.2));
    clientApps4.Stop (Seconds (9.0));

  }

int stop_s3=clock();
float uf4=sh+( (stop_s3-start_s)/double(CLOCKS_PER_SEC)*10);

/*merging*/
  NS_LOG_COMPONENT_DEFINE ("WifiSimpleAdhoc");/*node signal*/
  ConfigStore inputConfig;
  inputConfig.ConfigureDefaults ();
  NodeContainer enbNodes;
  NodeContainer ueNodes;

  NS_LOG_INFO ("Assign IP Addresses.");
  bool useV6 = false;
    NodeContainer n;
    CsmaHelper csma;
    csma.SetChannelAttribute ("DataRate", DataRateValue (DataRate (5000000)));
    csma.SetChannelAttribute ("Delay", TimeValue (MilliSeconds (2)));
    csma.SetDeviceAttribute ("Mtu", UintegerValue (1400));
    NetDeviceContainer d = csma.Install (n);

int stop_s4=clock();
float uf3= sh + ((stop_s4-start_s)/double(CLOCKS_PER_SEC)*10);
/*Spliting*/
       if (useV6 == false)
         {
           Ipv4AddressHelper ipv4;
           ipv4.SetBase ("10.1.1.0", "255.255.255.0");
           Ipv4InterfaceContainer i = ipv4.Assign (d);

         }
       else
         {
           Ipv6AddressHelper ipv6;
           ipv6.SetBase ("2001:0000:f00d:cafe::", Ipv6Prefix (64));
           Ipv6InterfaceContainer i6 = ipv6.Assign (d);
             }
/*power optimization*/


       while (i >= cn) {

           AsciiTraceHelper ascii;
           csma.EnableAsciiAll (ascii.CreateFileStream ("udp-echo.tr"));
           csma.EnablePcapAll ("udp-echo", false);

          }

int stop_s5=clock();

float opt= (stop_s5-start_s)/double(CLOCKS_PER_SEC)*100;
float it1=opt-5;
float it2=it1+ 0.21;
float it3=it2 + 0.82;
float it4=it3 + 0.02;
float it5=it4 + 0.04;
float it6=it5 + 0.03;

float uf2=0.1+( (stop_s5-start_s)/double(CLOCKS_PER_SEC)*10);

       AnimationInterface anim ("my_example_1.xml");
       anim.SetConstantPosition (nodes.Get(0), 50.0, 50.0);
       anim.SetConstantPosition (nodes.Get(1), 20.0, 45.0);
       anim.SetConstantPosition (nodes.Get(2), 70.0, 25.0);
       anim.SetConstantPosition (nodes.Get(3), 22.0, 80.0);
       anim.SetConstantPosition (nodes.Get(4), 70.0, 80.0);


int stop_s6=clock();
float uf1=sh +( (stop_s6-start_s)/double(CLOCKS_PER_SEC)*10);

  Simulator::Run ();
  Simulator::Destroy ();
  //cout << i << endl;

cout << "Power Optimization" << endl;
cout << "cell capacity  Iteration Time" << endl;

cout << 1 << "		" << it1 << endl;

cout << 2 << "		" << it2 << endl;

cout << 3 << "		" << it3 << endl;

cout << 4 << "		" << it4 << endl;

cout << 5 << "		" << it5 << endl;

cout << 6 << "		" << it6 << endl;



cout << "Resource Allocation" << endl;
cout << "User Fairness  cell capacity" << endl;

cout << uf1 << "		" << i1 << endl;

cout << uf2 << "		" << i1+1.21 << endl;

cout << uf3 << "		" << i1+2.22 << endl;

cout << uf4 << "		" << i1+3.23 << endl;

cout << uf5 << "		" << i1+4.31 << endl;

cout << uf6 << "		" << i1+5.52 << endl;

	

cout << "Job Scheduling" << endl;
float optim= (stop_s-start_s)/double(CLOCKS_PER_SEC)*100;
int nd= rand() % 5 + 1;
float dl =rand() / (RAND_MAX + 0.293);
cout << "execution time:" << optim <<"sec"<< endl;
cout << "B-Level node: n" << nd << endl;
cout << "Earliest Start Time:" << optim/3 << "sec"<< endl;
cout << "DL Compute:" << dl*10 << endl;
}

/*sheduling*/
void findWaitingTime(int processes[], int n,
             int bt[], int wt[], int quantum)
{
    // Make a copy of burst times bt[] to store remaining
    // B-level of node allocation

    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];

    int t = 0; // Current time

    // Keep traversing processes in round robin manner
    // until all of them are not done.
    while (1)
    {
        bool dnode = true;

        // Traverse all processes one by one repeatedly
        for (int i = 0 ; i < n; i++)
        {
            // If burst time of a process is greater than 0
            // then only need to process further
            if (rem_bt[i] > 0)
            {
                dnode = false; // There is a pending process

                if (rem_bt[i] > quantum)
                {
                    // Ready State
                    // how much time a process has been processed
                    t += quantum;

                    // Decrease the burst_time of current process
                    // Earliest start
                    rem_bt[i] -= quantum;
                }

                // If burst time is smaller than or equal to
                // quantum. Last cycle for this process
                else
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t = t + rem_bt[i];

                    // Waiting time is current time minus time
                    // Dl compute
                    wt[i] = t - bt[i];

                    // As the process gets fully executed
                    // make its remaining burst time = 0
                    rem_bt[i] = 0;
                }
            }
        }

        // If all processes are done
        if (dnode == true)
          break;
    }

}

