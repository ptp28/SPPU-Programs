package pass1;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;


public class Pass1 implements Serializable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File f = new File("Input.txt");
		Scanner sc = new Scanner(f);
		List<String> data = new ArrayList<String>();

		while(sc.hasNext())
		{
			data.add(sc.nextLine());
		}
		for(int i=0;i<data.size();i++)
			System.out.println(data.get(i));



		List<MDTrecord> MDT = new ArrayList<MDTrecord>();
		List<MNTrecord> MNT = new ArrayList<MNTrecord>();
		List<ALArecord> ALA = new ArrayList<ALArecord>();
		int MDTcount=0;
		int MNTcount=0;
		int ALAcount=0,argcount=0;
		String mname=new String();
		boolean nameflag=false;
		for(String thisLine : data)
		{
			String previousToken = new String();
			StringTokenizer st = new StringTokenizer(thisLine," ,");
			argcount=0;
			
			if(thisLine.startsWith("MACRO"))
			{
				nameflag=true;
				continue;
			}
			while(st.hasMoreTokens())
			{


				String thisToken = st.nextToken();
				if(nameflag==true)
				{
					mname=thisToken;
					MNT.add(new MNTrecord(++MNTcount, mname, MDTcount+1));
					nameflag=false;
				}
//				System.out.println("CURRENT TOKEN:\t"+thisToken);
//				System.out.println("PREV TOKEN:\t"+previousToken);

			
				if(thisToken.startsWith("&") && ALArecord.getRecord(ALA, thisToken,mname)==null )
				{
					ALA.add(new ALArecord(++ALAcount, thisToken,"-", mname));

				}
				
					//System.out.println("MDTENTRY: "+thisLine);
				previousToken=thisToken;
			}
			MDT.add(new MDTrecord(++MDTcount, thisLine));

			

		}
		System.out.println("\n\tMNT\n-------------------------------\nINDEX\tNAME\tMDT INDEX\n-------------------------------");
		for(MNTrecord a:MNT)
		{
			System.out.println(a.index+"\t"+a.name+"\t"+a.MDTindex);
		}

		System.out.println("\n\tALA\n-------------------------------\nINDEX\tDUMMY\tACTUAL\tMACRO\n-------------------------------");
		for(ALArecord a :ALA)
		{

			System.out.println(a.index+"\t"+a.dummy+"\t"+a.actual+"\t"+a.macro);
		}
		System.out.println("\n\tMDT\n-------------------------------\nINDEX\tINSTRUCTION\n-------------------------------");
		for(MDTrecord a:MDT)
		{
			System.out.println(a.index+"\t"+a.instruction);
		}
		
		new OutputWriter(MDT, MNT, ALA).writeOutput();
		
		sc.close();
		
	}
	public static class OutputWriter implements Serializable{
		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		public List<MDTrecord> MDT;
		public List<MNTrecord> MNT;
		public List<ALArecord> ALA;
		public OutputWriter(List<MDTrecord> MDT,		List<MNTrecord> MNT,		List<ALArecord> ALA) 
		{
			// TODO Auto-generated constructor stub
			this.ALA=ALA;
			this.MNT=MNT;
			this.MDT=MDT;
		}
		public void writeOutput() throws IOException {
			ObjectOutputStream oout = new ObjectOutputStream(new FileOutputStream("output.txt"));
			oout.writeObject(this);
			oout.close();
			oout = new ObjectOutputStream(new FileOutputStream("//home//soham//workspace//Macro Pass 2//output.txt"));
			oout.writeObject(this);
			oout.close();
		}
	}
	public static class MDTrecord implements Serializable{

		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		public int index;
		public String instruction;
		public MDTrecord() {
			// TODO Auto-generated constructor stub
			index=0;
			instruction=null;
		}
		public MDTrecord(int index,String instruction) {
			// TODO Auto-generated constructor stub
			this.index=index;
			this.instruction=instruction;
		}
		public static MDTrecord getRecord(List<MDTrecord> MDT ,String token) {
			for(MDTrecord a : MDT )
			{
				if(a.instruction.equals(token))
				{
					return a;
				}
			}
			return null;

		}


	}
	public static class MNTrecord implements Serializable{

		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		public int index;
		public String name;
		public int MDTindex;

		public MNTrecord(int index,String name,int MDTindex) {
			// TODO Auto-generated constructor stub
			this.index=index;
			this.MDTindex=MDTindex;
			this.name=name;
		}
		public static MNTrecord getRecord(List<MNTrecord> MNT,String token) {
			for(MNTrecord a : MNT)
			{
				if(a.name.equals(token))
				{
					return a;
				}
			}
			return null;

		}


	}
	public static class ALArecord implements Serializable{
		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		public int index;
		public String dummy;
		public String actual;
		public String macro;

		public ALArecord(int index, String dummy, String actual, String macro) {
			this.index = index;
			this.dummy = dummy;
			this.actual = actual;
			this.macro = macro;
		}

		public static ALArecord getRecord(List<ALArecord> ALA,String token,String mname) {
			for(ALArecord a : ALA)
			{
				if(a.dummy.equals(token) && a.macro.equals(mname))
				{
					return a;
				}
			}
			return null;

		}

	}
	

}
