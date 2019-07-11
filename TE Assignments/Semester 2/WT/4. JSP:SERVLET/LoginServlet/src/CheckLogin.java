

import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

/**
 * Servlet implementation class CheckLogin
 */
@WebServlet("/CheckLogin")
public class CheckLogin extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CheckLogin() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String userName = request.getParameter("username");
		String password = request.getParameter("password");
		try
		{  
			Class.forName("com.mysql.jdbc.Driver");  
			Connection con=DriverManager.getConnection(  
			"jdbc:mysql://localhost:3306/WT","root","");  
			      
			PreparedStatement ps=con.prepareStatement(  
			"select * from login where username=? and password=?");  
			ps.setString(1,userName);  
			ps.setString(2,password);  
			      
			ResultSet rs=ps.executeQuery();  
			while (rs.next()) 
			{
				response.sendRedirect("success.html");
			}
			response.sendRedirect("index.html");
			          
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}

}
