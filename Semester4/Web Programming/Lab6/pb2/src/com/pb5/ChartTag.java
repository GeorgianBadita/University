package com.pb5;


import javax.imageio.ImageIO;
import javax.servlet.annotation.WebServlet;
import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class ChartTag extends TagSupport {
    private String maxX;
    private String maxY;
    private String xPoints;
    private String yPoints;
    private String xLabel;
    private String yLabel;

    public void setColor(String color) {
        this.color = color.replaceAll("#", "%23");
    }

    private String color;

    public void setMaxX(String maxX) {
        this.maxX = maxX;
    }

    public void setMaxY(String maxY) {
        this.maxY = maxY;
    }

    public void setxPoints(String xPoints) {
        this.xPoints = xPoints;
    }

    public void setyPoints(String yPoints) {
        this.yPoints = yPoints;
    }

    public void setxLabel(String xLabel) {
        this.xLabel = xLabel;
    }

    public void setyLabel(String yLabel) {
        this.yLabel = yLabel;
    }

    public int doStartTag() throws JspException {
        JspWriter out=pageContext.getOut();//returns the instance of JspWriter

        try{
            String url = "http://localhost:8080/pb2_war_exploded/pb5/ChartDrawer?"
                    +"maxX=" + maxX
                    +"&maxY=" + maxY
                    +"&xPoints=" + xPoints
                    +"&yPoints=" + yPoints
                    +"&xLabel=" + xLabel
                    +"&yLabel=" + yLabel
                    +"&color=" + color;

            out.print("<img src=\"" + url + "\" alt=\"Graph\" />");
        }catch(Exception e){
            e.printStackTrace();
        }
        return SKIP_BODY;//will not evaluate the body content of the tag
    }
}
