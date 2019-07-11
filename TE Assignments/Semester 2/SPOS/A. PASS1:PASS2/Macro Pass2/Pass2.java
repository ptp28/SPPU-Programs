import java.io.File;
import java.io.FileNotFoundException;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;



public class Pass2 {
	static List< String> outputProgram = new ArrayList<String>();

	public static void main(String[] args) throws FileNotFoundException {
		File f = new File("Input.txt");
		Scanner sc = new Scanner(f);
		List<String> data = new ArrayList<String>();

		while(sc.hasNext())
		{
			data.add(sc.nextLine());
		}
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
				if(thisToken.startsWith("&") && ALArecord.getRecord(ALA, thisToken,mname)==null )
				{
					ALA.add(new ALArecord(++ALAcount, thisToken,"-", mname));

				}

			}
			MDT.add(new MDTrecord(++MDTcount, thisLine));

		}
		/*	System.out.println("\n\tMNT\n-------------------------------\nINDEX\tNAME\tMDT INDEX\n-------------------------------");
		for(MNTrecord a:MNT)
		{
			System.out.println(a.index+"\t"+a.name+"\t"+a.MDTindex);
		}

		System.out.println("\n\tALA\n-------------------------------\nINDEX\tDUMMY\tACTUAL\tMACRO\n-------------------------------");
		for(ALArecord a :ALA)
		{

			System.out.println(a.index+"\t"+a.dummy+"\t"+a.actual+"\t"+a.macro);
		}*/
		System.out.println("\n\tMDT\n-------------------------------\nINDEX\tINSTRUCTION\n-------------------------------");
		for(MDTrecord a:MDT)
		{
			System.out.println(a.index+"\t"+a.instruction);
		}
		executePass(ALA, MDT, MNT);


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

	public static  void callDefinitionOf (String mname,List<MDTrecord> MDT,String[] arguments ,List<ALArecord> ALA) {

//		System.out.println("\nARGS for call "+mname+"\t: ");
//		for(int k=0;k<arguments.length;k++)
//			System.out.print(arguments[k]);
		
		boolean macroStartFlag = false;

		for(MDTrecord m : MDT)
		{

		
			if(m.instruction.startsWith(mname))
			{	
				macroStartFlag=true;
				
				
				continue;
			}
			if(!m.instruction.equals("MEND") && macroStartFlag==true)
			{
				//System.out.println("adding instr: "+m.instruction);
				String instr = new String();
				for(int j=0 ; j<arguments.length; j++)
				{
					if(m.instruction.contains("&ARG"+(j+1)))
					{
//						System.out.println("Replacing &ARG"+(j+1)+" by "+arguments[j]);
						ALArecord temp = ALArecord.getRecord(ALA, "&ARG"+( j+1 ), mname);
						int indexOfRecord = ALA.indexOf(temp);
						ALA.set(indexOfRecord , new ALArecord(temp.index, temp.dummy, arguments[j], temp.macro));
						instr=m.instruction.replace("&ARG"+(j+1), arguments[j]);
					}
				}

				outputProgram.add(instr);
			}
			if(m.instruction.equals("MEND") && m.index+1<=MDT.size())
			{
				macroStartFlag=false;

			}


		}
	}


	public static void executePass(List< ALArecord> ALA,List< MDTrecord> MDT,List< MNTrecord> MNT) throws FileNotFoundException {
		File f = new File("InputPass2.txt");
		Scanner sc = new Scanner(f);
		List<String> data = new ArrayList<String>();

		while(sc.hasNext())
		{
			data.add(sc.nextLine());
		}
		for(int i=0;i<data.size();i++)
			System.out.println(data.get(i));

		String [] arguments=new String[20];
		for(String thisLine : data)
		{
			String nameFetch = new String();
			boolean isMacroCall = false;
			for( MNTrecord m : MNT)
			{
				if(thisLine.startsWith(m.name))
				{
					nameFetch=m.name;
					arguments = thisLine.split(" ");
					arguments=arguments[1].split(",");
//					for (int i = 0; i < arguments.length; i++) {
//						System.out.println("ARGS: "+arguments[i]);	
//					}
					
					isMacroCall=true;
					break;
				}
			}
			//	System.out.println(thisLine+" MACRO STATUS : ---- " +isMacroCall);
			if(isMacroCall==true)
			{
				callDefinitionOf(nameFetch, MDT,arguments,ALA);
				isMacroCall=false;
			}
			else
			{
				outputProgram.add(thisLine);
			}


		}

		System.out.println("\nOUTPUT PROGRAM:\n---------------------------------------------------");
		for (int i = 0; i < outputProgram.size(); i++) {
			System.out.println(outputProgram.get(i));

		}
		System.out.println("\n\tALA\n-------------------------------\nINDEX\tDUMMY\tACTUAL\tMACRO\n-------------------------------");
		for(ALArecord a :ALA)
		{

			System.out.println(a.index+"\t"+a.dummy+"\t"+a.actual+"\t"+a.macro);
		}
	}
}
