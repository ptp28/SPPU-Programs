import java.util.ArrayList;
import java.util.List;


public class Table {
	
	public static final List<MOT> mot = new ArrayList<MOT>();
	public static final List<POT> pot = new ArrayList<POT>();
	public static final List<RT> rt = new ArrayList<RT>();
	public static final List<CCBCI> ccbci = new ArrayList<CCBCI>();
	
	static {
		mot.add(new MOT("STOP", 0, 1));
		mot.add(new MOT("ADD", 1, 1));
		mot.add(new MOT("SUB", 2, 1));
		mot.add(new MOT("MUL", 3, 1));
		mot.add(new MOT("MOVER", 4, 1));
		mot.add(new MOT("MOVEM", 5, 1));
		mot.add(new MOT("COMP", 6, 1));
		mot.add(new MOT("BC", 7, 1));
		mot.add(new MOT("DIV", 8, 1));
		mot.add(new MOT("READ", 9, 1));
		mot.add(new MOT("PRINT", 10, 1));
		
		pot.add(new POT("START", 1));
		pot.add(new POT("END", 2));
		pot.add(new POT("ORIGIN", 3));
		pot.add(new POT("EQU", 4));
		pot.add(new POT("LTORG", 5));
		pot.add(new POT("DC", 6));
		pot.add(new POT("DS", 7));
		
		rt.add(new RT("AREG", 1));
		rt.add(new RT("BREG", 2));
		rt.add(new RT("CREG", 3));
		rt.add(new RT("DREG", 4));
		
		ccbci.add(new CCBCI("LT", 1));
		ccbci.add(new CCBCI("LE", 2));
		ccbci.add(new CCBCI("EQ", 3));
		ccbci.add(new CCBCI("GT", 4));
		ccbci.add(new CCBCI("GE", 5));
		ccbci.add(new CCBCI("NE", 6));
	}
	
	public static final void print() {
		System.out.println("\nMOT");
		System.out.printf("%10s %10s %10s\n", "Mnemonic", "Opcode", "Length");
		System.out.println("-----------------------------------------------");
		for (MOT m : mot) {
			System.out.printf("%10s %10s %10s\n", m.mnemonicOc, m.mcCode, m.length);
		}
		System.out.println("\nPOT");
		System.out.printf("%10s %10s\n", "Pseudo", "M/c Code");
		System.out.println("-----------------------------------------------");
		for (POT m : pot) {
			System.out.printf("%10s %10s\n", m.pseudoOc, m.mcCode);
		}
		System.out.println("\nRT");
		System.out.printf("%10s %10s\n", "Regname", "M/c Code");
		System.out.println("-----------------------------------------------");
		for (RT m : rt) {
			System.out.printf("%10s %10s\n", m.regName, m.mcCode);
		}
		System.out.println("\nCCBCI");
		System.out.printf("%10s %10s\n", "Condition", "M/c Code");
		System.out.println("-----------------------------------------------");
		for (CCBCI m : ccbci) {
			System.out.printf("%10s %10s\n", m.cond, m.mcCode);
		}
	}
	
	public static final class MOT {
		public String mnemonicOc;
		public int mcCode;
		public int length;
		
		public MOT(String mnemonicOc, int mcCode, int length) {
			this.mnemonicOc = mnemonicOc;
			this.mcCode = mcCode;
			this.length = length;
		}
		
		@Override
		public String toString() {
			return mnemonicOc;
		}
		
		public static MOT getByValue(String value) {
			for (MOT p : mot) {
				if (p.mnemonicOc.equals(value))
					return p;
			}
			return null;
		}
		
		public static MOT[] toArray() {
			return mot.toArray(new MOT[mot.size()]);
		}
	}
	
	public static final class POT {
		public String pseudoOc;
		public int mcCode;
		
		public POT(String pseudoOc, int mcCode) {
			this.pseudoOc = pseudoOc;
			this.mcCode = mcCode;
		}
		
		public static POT getByValue(String value) {
			for (POT p : pot) {
				if (p.pseudoOc.equals(value))
					return p;
			}
			return null;
		}
		
		public static POT[] toArray() {
			return pot.toArray(new POT[pot.size()]);
		}
		
		@Override
		public String toString() {
			return pseudoOc;
		}
		
	}
	
	public static final class RT {
		public String regName;
		public int mcCode;
		
		public RT(String regName, int mcCode) {
			this.regName = regName;
			this.mcCode = mcCode;
		}
		
		public static RT getByValue(String value) {
			for (RT p : rt) {
				if (p.regName.equals(value))
					return p;
			}
			return null;
		}
	}
	
	public static final class CCBCI {
		public String cond;
		public int mcCode;
		
		public CCBCI(String cond, int mcCode) {
			this.cond = cond;
			this.mcCode = mcCode;
		}
		
	}
	
}
