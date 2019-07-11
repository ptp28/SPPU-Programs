/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.pvg;

import java.io.IOException;
import java.io.PrintWriter;
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author CompLab4
 */
@WebServlet(name = "EJBCalciServlet", urlPatterns = {"/EJBCalciServlet"})
public class EJBCalciServlet extends HttpServlet {
 @EJB
         private EJBCalciLocal ejb1;
        
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
       
        //response.setContentType("text/html;charset=UTF-8");
        int n1=Integer.parseInt(request.getParameter("number1"));
        int n2=Integer.parseInt(request.getParameter("number2"));
        int result;
        String op=request.getParameter("op");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet EJBCalciServlet</title>");            
            out.println("</head>");
            out.println("<body>");
            if(op.equals("add"))
            {
                result=ejb1.add(n1, n2);
                out.println("Addition is:"+result);
            }
            if(op.equals("sub"))
            {
                result=ejb1.sub(n1, n2);
                out.println("Addition is:"+result);
            }
            if(op.equals("div"))
            {
                result=ejb1.div(n1, n2);
                out.println("Addition is:"+result);
            }
            if(op.equals("mul"))
            {
                result=ejb1.mul(n1, n2);
                out.println("Addition is:"+result);
            }
            
           // out.println("<h1>Servlet EJBCalciServlet at " + request.getContextPath() + "</h1>");
            out.println("</body>");
            out.println("</html>");
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
