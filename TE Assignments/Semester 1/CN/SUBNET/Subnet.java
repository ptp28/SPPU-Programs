import java.util.Scanner;


public class Subnet1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String ip;
		String mask="";
		int host=8;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter ip address :");
		ip=sc.next();
		String split_ip[]=ip.split("\\.");
		
		String Split_bip[]={"","","",""};
		String bip="";
		for(int i=0;i<4;i++)
		{
			Split_bip[i]=appendZeros(Integer.toBinaryString(Integer.parseInt(split_ip[i])));
			bip+=Split_bip[i];
		}
		System.out.println("IP in binary :"+bip);
		
		int firstoctet=Integer.parseInt(split_ip[0]);
		if(firstoctet<128)
		{
			host=24;
			mask="255.0.0.0";
		}
		else if(firstoctet<192)
		{
			host=16;
			mask="255.255.0.0";
		}
		else if(firstoctet<224)
		{
			host=8;
			mask="255.255.255.0";
		}
		System.out.println("Default subnet mask :"+mask);
		
		System.out.println("\n\n\nEnter no. of subnets :");
		int n=sc.nextInt();
		
		int x=(int)Math.ceil(Math.log(n)/Math.log(2));
		System.out.println("\n\n\nNo. of bits borrowed from host :"+x);
		
		int z=host-x;
		int mask1=256-(int)Math.pow(2, (8-x));
		//System.out.println("Subnetmask :"+mask1);
		System.out.println("Subentmask after Subnetting :"+newSubnet(mask1,firstoctet));
		int size=(int)Math.pow(2, z)-2;
		System.out.println("Subnet size :"+size);
		
		
		System.out.println("\n\n\nFirst subnet Details :");
		//First Network address
		int fbip[]=new int[32];
		String t[]={"","","",""};
		for(int i=0;i<32;i++)
		{
			fbip[i]=bip.charAt(i)-48;
		}
		for(int i=31;i>31-z;i--)
			fbip[i]&=0;
		for(int i=0;i<32;i++)
			t[i/8]=new String(t[i/8]+fbip[i]);
		System.out.println("First network address :");
		for(int i=0;i<4;i++)
		{
			System.out.print(Integer.parseInt(t[i],2));
			if(i!=3)
				System.out.print(".");
		}
		
		//Broadcast Address 
		int lbip[]=new int[32];
		String t1[]={"","","",""};
		for(int i=0;i<32;i++)
		{
			lbip[i]=bip.charAt(i)-48;
		}
		for(int i=31;i>31-z;i--)
			lbip[i]|=1;
		for(int i=0;i<32;i++)
			t1[i/8]=new String(t1[i/8]+lbip[i]);
		System.out.println("\nBroadcast address :");
		for(int i=0;i<4;i++)
		{
			System.out.print(Integer.parseInt(t1[i],2));
			if(i!=3)
				System.out.print(".");
		}
	
	}
	
	static String appendZeros(String s)
	{
		String temp="00000000";
		return temp.substring(s.length())+s;
	}
	
	static String newSubnet(int m,int firstoctet)
	{
	
		String mask="";
		if(firstoctet<128)
		{
			mask="255."+m+".0.0";
		}
		else if(firstoctet<192)
		{
			mask="255.255."+m+".0";
		}
		else if(firstoctet<224)
		{
			mask="255.255.255."+m;
		}
		return mask;
	}

}

/*Output
Enter ip address :
192.168.4.125
IP in binary :11000000101010000000010001111101
Default subnet mask :255.255.255.0

Enter no. of subnets :
4

No. of bits borrowed from host :2
Subentmask after Subnetting :255.255.255.192
Subnet size :62

First subnet Details :
First network address :
192.168.4.64
Broadcast address :
192.168.4.127
*/
