import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class tok {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new FileInputStream("input.txt"));
		List<Line> lines = new ArrayList<Line>();
		while (true) {
			Line mt = new Line(sc.nextLine());
			lines.add(mt);
			System.out.println(Arrays.asList(mt.tokens));
			if (mt.tokens[0].equals("END"))
				break;
		}
		pass1(lines);
		pass2();
		TableOut.print();
	}

	public static void pass1(List<Line> lines) {
		for (Line line : lines) {
			String label = null;
			do {
				if (!line.equalsFirst("EQU"))
					label = null;
				if (line.equalsFirst("START")) {
					TableOut.locCntr = Integer.parseInt(line.tokens[1]);
					TableOut.out.add(new TableOut.Out(-1, "(AD, 01)", -1, "(C, " + TableOut.locCntr + ")"));					
				} else if (line.equalsFirst("ORIGIN")) {
					String[] splits = line.tokens[1].split("\\+");
					int address = TableOut.SymTab.getByValue(splits[0]).address;
					TableOut.locCntr = address + Integer.parseInt(splits[1]);					
				} else if (line.equalsFirst("LTORG")) {
					int count = 0;
					for (TableOut.LitTab lt : TableOut.littab) {
						TableOut.out.add(new TableOut.Out(TableOut.locCntr, "(AD, 05)", -1, "" + lt.literal));
						lt.address = TableOut.locCntr++;						
						count++;					
					}
					TableOut.pooltab.add(count + 1);						
				} else if (line.equalsFirst("EQU")) {
					int address = TableOut.SymTab.getByValue(line.tokens[1]).address;
					TableOut.SymTab.getByValue(label).address = address;
					label = null;
				} else if (line.equalsFirst((Object[]) TableOut.SymTab.toArray())) {
					if (line.tokens[1].equals("DS")) {
						int length = Integer.parseInt(line.tokens[2]);
						TableOut.SymTab smt = TableOut.SymTab.getByValue(line.tokens[0]);
						smt.address = TableOut.locCntr;
						smt.length = length;
						TableOut.out.add(new TableOut.Out(TableOut.locCntr, "(AD, 07)", -1, "(C, 2)"));
						TableOut.locCntr += length;
					} else if (line.tokens[1].equals("DC")) {
						int length = 1;
						TableOut.SymTab smt = TableOut.SymTab.getByValue(line.tokens[0]);
						smt.address = TableOut.locCntr;
						smt.length = length;
						TableOut.out.add(new TableOut.Out(TableOut.locCntr, "(AD, 06)", -1, "(C, 3)"));
						TableOut.locCntr += length;
					}
				} else if (line.equalsFirst("END")) {
					int start = TableOut.pooltab.get(TableOut.pooltab.size() - 1);					
					for (TableOut.LitTab lt : TableOut.littab) {
						if (lt.litNo >= start) {
							TableOut.out.add(new TableOut.Out(TableOut.locCntr, "(AD, 02)", -1, "" + lt.literal));
							lt.address = TableOut.locCntr++;						
						}
					}					
				} else if (line.equalsFirst((Object[]) Table.MOT.toArray())) {
					int code = Table.MOT.getByValue(line.tokens[0]).mcCode;
					if (line.tokens[2].startsWith("=")) {
						int literal = Integer.parseInt(line.tokens[2].substring(2, line.tokens[2].length() - 1));
						TableOut.LitTab lt = TableOut.LitTab.getByValue(literal, TableOut.pooltab.get(TableOut.pooltab.size() - 1));
						if (lt == null) {
							TableOut.littab.add(lt = new TableOut.LitTab(++TableOut.littabPtr, literal, -1));	
						}						
						int opcode = Table.RT.getByValue(line.tokens[1]).mcCode;
						TableOut.out.add(new TableOut.Out(TableOut.locCntr, "(IS, " + code + ")", opcode, "(L, " + TableOut.littabPtr + ")"));
					} else {
						String symbol = line.tokens[2];
						TableOut.SymTab smt = TableOut.SymTab.getByValue(symbol);
						if (smt == null) {
							TableOut.symtab.add(smt = new TableOut.SymTab(symbol, TableOut.locCntr, -1));
							TableOut.symtabPtr++;
						}
						int index = TableOut.symtab.indexOf(smt) + 1;
						int opcode = Table.RT.getByValue(line.tokens[1]).mcCode;
						TableOut.out.add(new TableOut.Out(TableOut.locCntr, "(IS, " + code + ")", opcode, "(S, " + index + ")"));
					}
					TableOut.locCntr++;
				} else {
					TableOut.symtab.add(new TableOut.SymTab(line.tokens[0], TableOut.locCntr, 1));
					TableOut.symtabPtr++;
					label = line.remove(0);
				}
			} while (label != null);
		}
	}
	
	public static final void pass2() {
		for (TableOut.Out o : TableOut.out) {
			if (o.value == -1)
				continue;
			int lc = o.value;
			int opcode = Integer.parseInt(TableOut.Out2.parse(o.icOpcode)[1]);
			int op1 = o.op1;
			int op2 = -1;
			String[] arr = TableOut.Out2.parse(o.ic2);
			if (arr.length == 1) {
				op2 = Integer.parseInt(arr[0]);
			} else if (arr[0].equalsIgnoreCase("c")) {
				op2 = -1;
			} else if (arr[0].equalsIgnoreCase("s")) {
				op2 = TableOut.symtab.get(Integer.parseInt(arr[1]) - 1).address;
			} else if (arr[0].equalsIgnoreCase("l")) {
				op2 = TableOut.littab.get(Integer.parseInt(arr[1]) - 1).address;
			}
			TableOut.out2.add(new TableOut.Out2(lc, opcode, op1, op2));
		}
	}

	public static final class Line {
		private String str;
		private String[] tokens;

		public Line(String str) {
			this.str = str;
			form();
		}

		private void form() {
			StringTokenizer st = new StringTokenizer(str, " ,\t");
			List<String> tokens = new ArrayList<String>();
			while (st.hasMoreTokens()) {
				tokens.add(st.nextToken().replaceAll("\\s+", ""));
			}
			this.tokens = tokens.toArray(new String[tokens.size()]);
		}

		public boolean equalsFirst(Object... str) {
			for (Object s : str) {
				if (tokens[0].equalsIgnoreCase(s.toString()))
					return true;
			}
			return false;
		}
		
		public String remove(int i) {
			List<String> tokens = new ArrayList<String>(Arrays.asList(this.tokens));
			String s = tokens.remove(i);
			this.tokens = tokens.toArray(new String[tokens.size()]);
			return s;
		}

		public void display() {
			for (int i = 0; i < tokens.length; i++) {
				System.out.println(i + ": " + tokens[i]);
			}
		}

	}

}
