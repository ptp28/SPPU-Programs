import java.util.*;
import java.io.*;


class smbt{
 int no;
 String smyb;
 int add=-1; 

 int checkAlrdyExist(String symbol)
 {
 	if(this.smyb.equals(symbol))
 		return 1;
 	return 0;
 }
 int changeAdd(String symbol,int add)
 {
 	if(this.smyb.equals(symbol))
 	{
 		this.add = add;
 		return 1;
 	}
 	return 0;
 }
 String display()
 {
    System.out.println(no+" "+smyb+" "+add);
    return no+" "+smyb+" "+add;
 }
}

class litt{
 int no;
 String lit;
 int add=-1;

 int checkAlrdyExist(String literal)
 {
 	if(this.lit.equals(literal))
 		return 1;
 	return 0;
 }
 String changeAdd(int add)
 {
 	this.add = add;
 	return lit;
 }
 String display()
 {
    System.out.println(no+" "+lit+" "+add);
    return no+" "+lit+" "+add;
 }
}

class poolt{
	int pool;
 
 String display()
 {
    System.out.println(pool);
    return Integer.toString(pool);
 }
}


class a
{
 public static void main(String args[]) throws Exception
 {
 	System.out.println("asdaskd");

 	String nextLine, output = "";
 	int syp = 0, ltp = 0, pt = 0, lc = 0, check;

	Scanner sc = new Scanner(new FileInputStream("input.txt")); 
	
	List<smbt> syl = new ArrayList<smbt>();
	List<litt> ltl = new ArrayList<litt>();
	List<poolt> ptl = new ArrayList<poolt>();

	String mot[] = {"STOP","ADD","SUB","MUL","MOVER","MOVEM","COMP","BC","DIV","READ","PRINT"};
	String pot[] = {" ","START","END","EQU","ORIGIN","LTORG"};
	String reg[] = {"","AREG","BREG","CREG","DREG"};

	poolt p = new poolt();
 	p.pool = pt;
 	ptl.add(p);

	while(true)
	{

		nextLine =  sc.nextLine();		
 		String split[] = nextLine.split("	");
 					
 		if(checkExist(pot,6,nextLine)!=-1)
 		{
 			check=checkExist(pot,6,nextLine);
 			if(check == 2)
 			{
 				output = output + nextLine+ "\t\t\t\t     (IS,1)\n"; 
				for(int i=pt ; i<ltl.size(); i++)
 				{
 					String literal = ltl.get(i).changeAdd(lc);
 					output = output + "\t\t\t\t\t"+lc+") (DL,2) (C,"+literal+")\n";
 					lc++;
 				}
 				break;
 			}
 			switch(check)
 			{
 				case 1:
 					
 					try{
 						lc = Integer.parseInt(split[2]);
 					}
 					catch(Exception e){}
 					output = output + nextLine+ "\t\t\t     (IS,0) (C,"+lc+")\n"; 
 					break;

 				case 3:
 					break;
 				case 4:
 					 					
 					try{
 						lc = Integer.parseInt(split[2]);
 					}
 					catch(Exception e){}
 					output = output + nextLine+ "\t\t\t     (IS,4) (C,"+lc+")\n"; 
 					
 					break;
 				case 5:
 					for(int i=pt ; i<ltl.size(); i++)
 					{
 						String literal = ltl.get(i).changeAdd(lc);
 						if(i==pt)
 							output = output + nextLine+"\t\t\t\t"+lc+") (DL,2) (C,"+literal+")\n";	
 						else
 							output = output + "\t\t\t\t\t"+lc+") (DL,2) (C,"+literal+")\n";
 						lc++;
 					}
 					pt = ltl.size()-1;
 					p = new poolt();
 					p.pool = pt;
 					ptl.add(p);
 					pt = ltl.size();
 					break;
 			}
 		}
 		else if(checkExist(mot,11,nextLine) != -1)
 		{//if mot array is in the line
 			check = checkExist(mot,11,nextLine);
 			int chkExistInTable = 0;
 				
 			if(!split[0].equals(""))//if label is in the line
 			{
 				
 				smbt s = new smbt();
		 		s.no = syp;
		 		s.smyb = split[0];
		 		s.add = lc;
		 		syl.add(s);
		 		syp++;
 			}
 			String motMethod = split[1];
 			String str2Split[] = split[2].split(",");
 			int check2 = checkExist(reg,5,str2Split[0]);
 				
 			if(split[2].contains("="))//check for literal
 			{
 				litt l = new litt();
	 			l.no = ltp;
	 			l.lit = str2Split[1];
	 			ltl.add(l);
	 			output = output + nextLine+ "\t\t"+ lc+") (AD,"+check+") (RG,"+check2+") (L,"+ltp+")\n";
	 			lc++;
	 			ltp++;
 								
 			}
 			else
 			{//symbol in line
 				for(int i=0 ;i < syl.size() ; i++)
 				{
 					chkExistInTable = syl.get(i).checkAlrdyExist(str2Split[1]);
 					if(chkExistInTable == 1)
 					{
 						output = output + nextLine+ "\t\t\t"+ lc+") (AD,"+check+") (RG,"+check2+") (S,"+i+")\n";
 						lc++;
 						break;
 					}
 				}
 				if(chkExistInTable == 0)
 				{
	 				smbt s = new smbt();
	 				s.no = syp;
	 				s.smyb = str2Split[1];
	 				syl.add(s);
	 				output = output + nextLine+ "\t\t\t"+ lc+") (AD,"+check+") (RG,"+check2+") (S,"+syp+")\n";
	 				lc++;
	 				syp++;
	 			}
 			}	
 		}
 		else if(split[0]!="")
 		{
 			int chkAddChanged = -1;
 			for(int i=0 ;i < syl.size() ; i++)
 			{
 				chkAddChanged = syl.get(i).changeAdd(split[0],Integer.parseInt(split[2]));
 				if(chkAddChanged == 1)
 				{
 					if(split[1].equals("DS"))
 					{
 						output = output + nextLine+ "\t\t\t"+ lc+") (DL,1) (C,"+split[2]+")\n";
 						lc = lc + Integer.parseInt(split[2]);
 					}
 					else
 					{
 						output = output + nextLine+ "\t\t\t"+ lc+") (DL,2) (C,"+split[2]+")\n";
 						lc = lc++;
 					}
 					break;
 				}
 			}
 			
 		}	
 	}

 	System.out.println(output);
	System.out.println();
	String sytab="",littab="",pooltab = "";

    for (int j = 0; j < syl.size(); j++) {
               sytab=sytab+syl.get(j).display()+"\n";
    }
    System.out.println();

    for (int j = 0; j < ltl.size(); j++) {
            littab = littab+ltl.get(j).display()+"\n";
    }
    System.out.println();

    for (int j = 0; j < ptl.size(); j++) {
            pooltab = pooltab+ptl.get(j).display()+"\n";
    }

 	BufferedWriter writer = new BufferedWriter(new FileWriter("intercode.txt"));
    writer.write(output);
    writer.close(); 

    BufferedWriter writer1 = new BufferedWriter(new FileWriter("symbol.txt"));
    writer1.write(sytab);
    writer1.close();

    BufferedWriter writer2 = new BufferedWriter(new FileWriter("literal.txt"));
    writer2.write(littab);
    writer2.close();

    BufferedWriter writer3 = new BufferedWriter(new FileWriter("pool.txt"));
    writer3.write(pooltab);
    writer3.close();
 }

 static int checkExist(String array[],int size, String check)
 {
 	for(int i=0 ; i<size ; i++){
 		if(check.contains(array[i]))
 			return i;
 	}
 	return -1;
 }
}