<%-- 
    Document   : login
    Created on : Mar 22, 2019, 9:06:32 AM
    Author     : CompLab4
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <form action="loginform.do" method="post">
	Username : <input type="text" name="uname" />
		<br>
	Password : <input type="password" name="upass" />
		<br>
		<input type="submit" value="login" />
	</html:form>

    </body>
</html>
