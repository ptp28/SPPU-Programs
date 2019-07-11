import java.util.ArrayList;
import java.util.List;

public class TableOut {
	
	public static int locCntr = 0;
	public static int pooltabPtr = 0;
	public static int littabPtr = 0;
	public static int symtabPtr = 0;

	public static final List<SymTab> symtab = new ArrayList<SymTab>();
	public static final List<LitTab> littab = new ArrayList<LitTab>();
	public static final List<Integer> pooltab = new ArrayList<Integer>();
	public static final List<Out> out = new ArrayList<Out>();
	public static final List<Out2> out2 = new ArrayList<Out2>();
	
	static {
		pooltab.add(1);
	}
	
	public static void print() {
		System.out.println("\nLocation Counter: " + locCntr);
		System.out.println("Pooltab Pointer: " + pooltabPtr);
		System.out.println("Literal Tab Pointer: " + littabPtr);
		System.out.println("Symbol Table Pointer: " + symtabPtr);
		System.out.println("\nOut");
		System.out.printf("%10s %10s %10s %10s\n", "L/c Value", "Ic for Opcode", "Op1", "Ic for op2");
		System.out.println("-----------------------------------------------");
		for (Out m : out) {
			System.out.printf("%10s %10s %10s %10s\n", m.value, m.icOpcode, m.op1, m.ic2);
		}
		System.out.println("\nOut2");
		System.out.printf("%10s %10s %10s %10s\n", "L/c Value", "Ic for Opcode", "Op1", "Op2");
		System.out.println("-----------------------------------------------");
		for (Out2 m : out2) {
			System.out.printf("%10s %10s %10s %10s\n", m.lc, m.opcode, m.op1, m.op2);
		}
		System.out.println("\nSymbol Table");
		System.out.printf("%10s %10s %10s\n", "name", "address", "length");
		System.out.println("-----------------------------------------------");
		for (SymTab m : symtab) {
			System.out.printf("%10s %10s %10s\n", m.name, m.address, m.length);
		}
		System.out.println("\nLiteral Table");
		System.out.printf("%10s %10s %10s\n", "literal no", "literal", "address");
		System.out.println("-----------------------------------------------");
		for (LitTab m : littab) {
			System.out.printf("%10s %10s %10s\n", m.litNo, m.literal, m.address);
		}
		System.out.println("\nPool Table");
		System.out.printf("%10s\n", "Pool no");
		System.out.println("-----------------------------------------------");
		for (Integer m : pooltab) {
			System.out.printf("%10s\n", m);
		}
	}

	public static final class SymTab {
		public String name;
		public int address;
		public int length;

		public SymTab(String name, int address, int length) {
			this.name = name;
			this.address = address;
			this.length = length;
		}
		
		public static SymTab getByValue(String value) {
			for (SymTab p : symtab) {
				if (p.name.equals(value))
					return p;
			}
			return null;
		}
		
		public static String[] toArray() {
			List<String> list = new ArrayList<String>();
			for (SymTab smt : symtab) {
				if (smt.length == -1)
					list.add(smt.name);
			}
			return list.toArray(new String[list.size()]);
		}		
	}

	public static final class LitTab {
		public int litNo;
		public int literal;
		public int address;

		public LitTab(int litNo, int literal, int address) {
			this.litNo = litNo;
			this.literal = literal;
			this.address = address;
		}
		
		public static LitTab getByValue(int value, int no) {
			for (LitTab p : littab) {
				if (p.literal == value && p.litNo >= no)
					return p;
			}
			return null;
		}
	}
	
	public static final class Out {
		public int value;
		public String icOpcode;
		public int op1;
		public String ic2;
		
		public Out(int value, String icOpcode, int op1, String ic2) {
			this.value = value;
			this.icOpcode = icOpcode;
			this.op1 = op1;
			this.ic2 = ic2;
		}
	}
	
	public static final class Out2 {
		public int lc;
		public int opcode;
		public int op1;
		public int op2;
		
		public Out2(int lc, int opcode, int op1, int op2) {
			this.lc = lc;
			this.opcode = opcode;
			this.op1 = op1;
			this.op2 = op2;
		}
		
		public static String[] parse(String s) {
			String[] arr = s.replaceAll("[ ()]", "").split(",");
			return arr;
		}
	}
}
