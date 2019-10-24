package com.pb6;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(urlPatterns = {"/pb6/GameStatus"}, asyncSupported = true)
public class GameStatus extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String table = (String)req.getSession().getAttribute("table");

        Character winner = checkGameStatus(table);

        try {
            ServletOutputStream out = resp.getOutputStream();

            out.print(winner);
        } catch (IOException e) {
            System.out.println("InputOutput ex");
        }
    }

    private static Character checkGameStatus(String table) {
        if (table.charAt(0) == 'X' && table.charAt(1) == 'X' && table.charAt(2) == 'X')
            return 'X';
        if (table.charAt(3) == 'X' && table.charAt(4) == 'X' && table.charAt(5) == 'X')
            return 'X';
        if (table.charAt(6) == 'X' && table.charAt(7) == 'X' && table.charAt(8) == 'X')
            return 'X';

        if (table.charAt(0) == 'X' && table.charAt(3) == 'X' && table.charAt(6) == 'X')
            return 'X';
        if (table.charAt(1) == 'X' && table.charAt(4) == 'X' && table.charAt(7) == 'X')
            return 'X';
        if (table.charAt(2) == 'X' && table.charAt(5) == 'X' && table.charAt(8) == 'X')
            return 'X';

        if (table.charAt(0) == 'X' && table.charAt(4) == 'X' && table.charAt(8) == 'X')
            return 'X';
        if (table.charAt(2) == 'X' && table.charAt(4) == 'X' && table.charAt(6) == 'X')
            return 'X';



        if (table.charAt(0) == 'O' && table.charAt(1) == 'O' && table.charAt(2) == 'O')
            return 'O';
        if (table.charAt(3) == 'O' && table.charAt(4) == 'O' && table.charAt(5) == 'O')
            return 'O';
        if (table.charAt(6) == 'O' && table.charAt(7) == 'O' && table.charAt(8) == 'O')
            return 'O';

        if (table.charAt(0) == 'O' && table.charAt(3) == 'O' && table.charAt(6) == 'O')
            return 'O';
        if (table.charAt(1) == 'O' && table.charAt(4) == 'O' && table.charAt(7) == 'O')
            return 'O';
        if (table.charAt(2) == 'O' && table.charAt(5) == 'O' && table.charAt(8) == 'O')
            return 'O';

        if (table.charAt(0) == 'O' && table.charAt(4) == 'O' && table.charAt(8) == 'O')
            return 'O';
        if (table.charAt(2) == 'O' && table.charAt(4) == 'O' && table.charAt(6) == 'O')
            return 'O';

        return '_';
    }
}
