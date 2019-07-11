

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class JDBCActions
 */
@WebServlet("/JDBCActions")
public class JDBCActions extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JDBCActions() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		Connection conn;
		PreparedStatement ps;
		ResultSet rs;
		
		String insertName = request.getParameter("insertName");
		String insertSalary = request.getParameter("insertSalary");
		String insertPost = request.getParameter("insertPost");
		String deleteName = request.getParameter("deleteName");
		String existingName = request.getParameter("existingName");
		String newSalary = request.getParameter("newSalary");
		String newPost = request.getParameter("newPost");
		String operation = request.getParameter("Submit");
		
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		out.println("<HTML>");
		out.println("<HEAD>");
		out.println("<TITLE> RESULT </TITLE>");
		out.println("<STYLE> body { background-image: linear-gradient(to bottom right,orange,red); } td { border-bottom: solid; } .value{color: white;} </STYLE>");
		out.println("</HEAD>");
		out.println("<BODY>");
		
		try 
		{
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/WT","root","");
			
			switch(operation)
			{
			case "INSERT" :
				ps = conn.prepareStatement("INSERT INTO `employee`(`name`, `salary`, `post`) VALUES (?,?,?);");
				ps.setString(1, insertName);
				ps.setString(2, insertSalary);
				ps.setString(3, insertPost);
				ps.executeUpdate();
				out.println("<h2>INSERT SUCCESSFUL</h2>");
				out.println("<br> Inserted Name - " + insertName);
				out.println("<br> Inserted Salary - " + insertSalary);
				out.println("<br> Inserted Post - " + insertPost);
				out.println("<br><a href='index.html'>[RETURN TO MAIN MENU]</a>");
				break;
			case "UPDATE" :
				ps = conn.prepareStatement("UPDATE `employee` SET `salary`=?,`post`=? WHERE name=?;");
				ps.setString(1, newSalary);
				ps.setString(2, newPost);
				ps.setString(3, existingName);
				ps.executeUpdate();
				out.println("<h2>UPDATE SUCCESSFUL</h2>");
				out.println("<br> Affected Employee - " + existingName);
				out.println("<br> New Salary - " + newSalary);
				out.println("<br> New Post - " + newPost);
				out.println("<br><a href='index.html'>[RETURN TO MAIN MENU]</a>");
				break;
			case "DELETE" :
				ps = conn.prepareStatement("DELETE FROM `employee` WHERE name = ? ;");
				ps.setString(1, deleteName); 
				ps.executeUpdate();
				out.println("<h2>DELETE SUCCESSFUL</h2>");
				out.println("<br> Deleted Employee - " + deleteName);
				out.println("<br><a href='index.html'>[RETURN TO MAIN MENU]</a>");
				break;
			case "DISPLAY" :
				ps = conn.prepareStatement("SELECT * FROM `employee` WHERE 1"); 
				rs = ps.executeQuery();
				out.println("<h2>LIST OF EMPLOYEES</h2>");
				out.println("<table cellspacing=10 cellpadding=5>");
				while(rs.next())
				{
					out.println("<tr>");
						out.println("<td>");
							out.println("NAME : ");
						out.println("</td>");
						out.println("<td class='value'><b>");
							out.println(rs.getString("name"));
						out.println("</b></td>");
						out.println("<td>");
							out.println("SALARY : ");
						out.println("</td>");
						out.println("<td class='value'><b>");
							out.println(rs.getInt("salary"));
						out.println("</b></td>");
						out.println("<td>");
							out.println("POST : ");
						out.println("</td>");
						out.println("<td class='value'><b>");
							out.println(rs.getString("post"));
						out.println("</b></td>");
					out.println("</tr>");
				}
				out.println("</table>");
				out.println("<br><a href='index.html'>[RETURN TO MAIN MENU]</a>");
				break;
			}
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		
		out.println("</BODY>");
		out.println("</HTML>");
		out.close();
	}

}