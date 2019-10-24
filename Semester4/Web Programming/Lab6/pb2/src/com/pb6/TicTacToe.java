package com.pb6;

import javax.json.Json;
import javax.json.JsonObject;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.*;


@WebServlet(urlPatterns = {"/pb6/TicTacToe"}, asyncSupported = true)
public class TicTacToe extends HttpServlet {
    private Map<Integer, Integer> game_ids_and_number_of_players = new HashMap<>();
    private Map<Integer, String> game_statuses = new HashMap<>();
    private Integer currentGameID = 1;

    @Override
    public void doGet(HttpServletRequest req, HttpServletResponse res) {
        if (req.getSession().getAttribute("game_id") == null) {
            if (game_ids_and_number_of_players.containsKey(currentGameID)) {
                game_ids_and_number_of_players.put(currentGameID, 2);
                req.getSession().setAttribute("game_id", currentGameID);
                req.getSession().setAttribute("mark", "O");
                game_statuses.put(currentGameID, "_________");
                currentGameID++;
                System.out.println("Sunt 2 playeri,the game may begin");
            }
            else {
                game_ids_and_number_of_players.put(currentGameID, 1);
                req.getSession().setAttribute("game_id", currentGameID);
                req.getSession().setAttribute("mark", "X");
                System.out.println("Este doar un player,a fost setata sesiunea " + currentGameID.toString());
            }
        }
        else {
            Integer game_id = (Integer)req.getSession().getAttribute("game_id");
            //System.out.println("are deja GID = " + String.valueOf(game_id));
            String table = game_statuses.get(game_id);

            try {
                ServletOutputStream out = res.getOutputStream();
                if (game_ids_and_number_of_players.get(game_id) == 2) {
                    out.print(table);
                    req.getSession().setAttribute("table", table);
                    //out.print(checkGameStatus(table));

//                    JsonObject json = Json.createObjectBuilder().add("table", table).add("status", checkGameStatus(table)).build();
//                    System.out.println(json.toString());
//                    out.print(json.toString());
                }
                else
                    out.print("Still waiting for a worthy oponnent!");
            } catch (IOException e) {
                System.out.println("InputOutput ex");
            }
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Integer game_id = (Integer)req.getSession().getAttribute("game_id");
        if (game_id != null) {
            String oldTable = game_statuses.get(game_id);
            System.out.println("OLD=" + oldTable);
            String newTable = req.getParameter("table");
            System.out.println("NEW=" + newTable);
            game_statuses.put(game_id, newTable);
//
//            String diff = StringUtils.difference(newTable, oldTable);
//            System.out.println("DIFF=" + diff);
//            if (mark.equals(diff.charAt(0))) {
//            }
//            else
//                System.out.println("Invalid move!");
        }
    }


}
