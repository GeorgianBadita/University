package com.pb5;


import javax.imageio.ImageIO;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.OutputStream;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

@WebServlet(name = "ChartDrawer", urlPatterns = {"/pb5/ChartDrawer"})
public class ChartDrawer extends HttpServlet {
    private static final int yMax = 20;
    private static final int PREF_W = 800;
    private static final int PREF_H = 650;
    private static final int BORDER_GAP = 30;
    private static final Color GRAPH_COLOR = Color.green;
    private static final Stroke GRAPH_STROKE = new BasicStroke(3f);
    private static final int GRAPH_POINT_WIDTH = 12;

    public Integer getxMax(String maxXString) {
        Integer maxX = 0;
        try {
            maxX = Integer.valueOf(maxXString);
        } catch (NumberFormatException e) {
            System.out.println("Eroare la parsare numar");
        }
        return maxX;
    }
    public Integer getyMax(String maxYString) {
        Integer maxY = 0;
        try {
            maxY = Integer.valueOf(maxYString);
        } catch (NumberFormatException e) {
            System.out.println("Eroare la parsare numar maxY");
        }
        return maxY;
    }
    public ArrayList<Integer> getxPoints(String xPointsString) {
        ArrayList<Integer> xPoints = new ArrayList<>();
        try {
            String[] data = xPointsString.split(",");
            for (int i = 0; i < data.length; i++)
                xPoints.add(Integer.valueOf(data[i]));
        } catch (NumberFormatException e) {
            System.out.println("eroare la setXPoints parsing");
        }
        return xPoints;
    }
    public ArrayList<Integer> getyPoints(String yPointsString) {
        ArrayList<Integer> yPoints = new ArrayList<>();
        try {
            String[] data = yPointsString.split(",");
            for (int i = 0; i < data.length; i++)
                yPoints.add(Integer.valueOf(data[i]));
        } catch (NumberFormatException e) {
            System.out.println("eroare la setYPoints parsing");
        }
        return yPoints;
    }


    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        processRequest(request, response);
    }

    private void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Integer xMax = getxMax(request.getParameter("maxX"));
        Integer yMax = getyMax(request.getParameter("maxY"));
        ArrayList<Integer> xPoints = getxPoints(request.getParameter("xPoints"));
        ArrayList<Integer> yPoints = getyPoints(request.getParameter("yPoints"));
        String xLabel = request.getParameter("xLabel");
        String yLabel = request.getParameter("yLabel");
        int width = 820;
        int height = 650;
        Color GRAPH_POINT_COLOR = Color.decode(request.getParameter("color"));
        System.out.println(request.getParameter("color"));
        //folosim o imagine buffer pentru a desena captcha-ul
        BufferedImage bufImg = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        Graphics2D g2d = bufImg.createGraphics();
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        double xScale = 80;//((double) PREF_W - 2 * BORDER_GAP) / (xMax - 1);
        double yScale = 40;//((double) PREF_H - 2 * BORDER_GAP) / (yMax - 1);

        List<Point> graphPoints = new ArrayList<Point>();
        for (int i = 0; i < xPoints.size(); i++) {
            int x1 = (int) (xPoints.get(i) * xScale + BORDER_GAP);
            int y1 = (int) ((yMax - yPoints.get(i)) * yScale + BORDER_GAP) + height / 2;
            graphPoints.add(new Point(x1, y1));
        }

        // create x and y axes 
        g2d.drawLine(BORDER_GAP, PREF_H - BORDER_GAP, BORDER_GAP, BORDER_GAP);
        g2d.drawLine(BORDER_GAP, PREF_H - BORDER_GAP, PREF_W - BORDER_GAP, PREF_H - BORDER_GAP);

        Stroke oldStroke = g2d.getStroke();
        g2d.setColor(GRAPH_COLOR);
        g2d.setStroke(GRAPH_STROKE);
        for (int i = 0; i < graphPoints.size() - 1; i++) {
            int x1 = graphPoints.get(i).x;
            int y1 = graphPoints.get(i).y;
            int x2 = graphPoints.get(i + 1).x;
            int y2 = graphPoints.get(i + 1).y;
            g2d.drawLine(x1, y1, x2, y2);
        }

        g2d.setStroke(oldStroke);
        g2d.setColor(GRAPH_POINT_COLOR);
        for (int i = 0; i < graphPoints.size(); i++) {
            int x = graphPoints.get(i).x - GRAPH_POINT_WIDTH / 2;
            int y = graphPoints.get(i).y - GRAPH_POINT_WIDTH / 2;;
            int ovalW = GRAPH_POINT_WIDTH;
            int ovalH = GRAPH_POINT_WIDTH;
            g2d.fillOval(x, y, ovalW, ovalH);
        }
        Font font = new Font("Georgia", Font.BOLD, 21);
        g2d.setFont(font);
        g2d.drawString(xLabel, 350, 641);
        g2d.drawString(yLabel, 10, 25);
        g2d.dispose();

        response.setContentType("image/png");
        OutputStream os = response.getOutputStream();
        ImageIO.write(bufImg, "png", os);
        os.close();

    }

}
