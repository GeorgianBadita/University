package com.pb2;

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
import java.util.Random;

@WebServlet(name = "CaptchaServlet", urlPatterns = {"/CaptchaServlet"})
public class CaptchaServlet extends HttpServlet {
    private void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //latimea si inaltimea imaginii
        int width = 250;
        int height = 100;
        //vectorul de captcha-uri
//        char data[][] = {
//            { 'm', 'a', 'n', 'c', 'a', 'r', 'e' },
//            { 'b', 'e', 't', 'o', 'n' },
//            { 'f', 'r', 'i', 'g', 'i', 'd', 'e', 'r' },
//            { 's', 'u', 'p', 'e', 'r', 'm', 'a', 'n' },
//            { 'j', 'e', 't' }
//        };

        //folosim o imagine buffer pentru a desena captcha-ul
        BufferedImage bufImg = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        Graphics2D g2d = bufImg.createGraphics();
        Font font = new Font("Georgia", Font.BOLD, 18);
        g2d.setFont(font);
        g2d.setColor(Color.WHITE);

        //folosim hint-uri ca sa crestam calitatea textului din poza
        RenderingHints rHints = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        rHints.put(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY);
        g2d.setRenderingHints(rHints);

        //desenam gradientul, pentru fundalul imaginii
        GradientPaint gPaint = new GradientPaint(0, 0, Color.BLUE, 0, height/2, Color.black, true);
        g2d.setPaint(gPaint);
        g2d.fillRect(0, 0, width, height);
        g2d.setColor(new Color(255, 153, 0));

        //numar random pt vectorul de captcha-uri
        Random rand = new Random();
        char data[][] = {{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
        for (int i = 0; i < 8; i++) {
            char r = rndChar();
            data[0][i] = r;
        }
        //int index = Math.abs(rand.nextInt()) % 5;
        int index = 0;
        //trimitem stringul la user sa stie sa compare input-ul de la user
        String captcha = String.copyValueOf(data[index]);
        request.getSession().setAttribute("captcha", captcha);

        //desenam captcha-ul ales in imagine
        int x = 0, y = 0;
        for (int i = 0; i < data[index].length; i++) {
            x += 15 + Math.abs(rand.nextInt()) % 15;
            y = 45 + Math.abs(rand.nextInt()) % 20;
            g2d.drawChars(data[index], i, 1, x, y);
        }
        g2d.dispose();

        response.setContentType("image/png");
        OutputStream os = response.getOutputStream();
        ImageIO.write(bufImg, "png", os);
        os.close();
    }
    
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        processRequest(request, response);
    }
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        processRequest(request, response);
    }

    private static char rndChar () {
        int rnd = (int) (Math.random() * 52); // or use Random or whatever
        char base = (rnd < 26) ? 'A' : 'a';
        return (char) (base + rnd % 26);

    }
}