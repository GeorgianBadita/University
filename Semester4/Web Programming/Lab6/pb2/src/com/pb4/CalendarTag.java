package com.pb4;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class CalendarTag extends TagSupport {
    private String an, luna, zi, culoare, clasa;

    public void setAn(String an) {
        this.an = an;
    }

    public void setLuna(String luna) {
        this.luna = luna;
    }

    public void setZi(String zi) {
        this.zi = zi;
    }

    public void setCuloare(String culoare) {
        this.culoare = culoare;
    }

    public void setClasa(String clasa) {
        this.clasa = clasa;
    }

    public int doStartTag() throws JspException {
        JspWriter out=pageContext.getOut();//returns the instance of JspWriter
        try{
            if (an != null && luna != null) {
                Calendar calendar = Calendar.getInstance();
                calendar.set(Integer.valueOf(an), Integer.valueOf(luna) - 1, 1, 0, 0);

                //out.print(calendar.toString());
                int dayOfWeek = calendar.get(Calendar.DAY_OF_WEEK); //get day of week for 1st of month
                System.out.println(dayOfWeek);
                int daysInMonth = calendar.getActualMaximum(Calendar.DAY_OF_MONTH);
                String defaultClass = "table";
                if (clasa != null)
                    defaultClass = clasa;
                out.println(new SimpleDateFormat("MMMM YYYY").format(calendar.getTime()));
                out.println("<br>");
                out.println("<table class=\"" + defaultClass + "\">");
                    out.println("<tr>");
                        out.println("<th>S</th>");
                        out.println("<th>M</th>");
                        out.println("<th>T</th>");
                        out.println("<th>W</th>");
                        out.println("<th>T</th>");
                        out.println("<th>F</th>");
                        out.println("<th>S</th>");
                    out.println("</tr>");
                //print initial spaces
                out.println("<tr>");
                String initialSpace = "";
                for (int i = 0; i < dayOfWeek - 1; i++) {
                    initialSpace += "<td></td>";
                }
                out.print(initialSpace);

                //print the days of the month starting from 1
                for (int i = 0, dayOfMonth = 1; dayOfMonth <= daysInMonth; i++) {
                    for (int j = ((i == 0) ? dayOfWeek - 1 : 0); j < 7 && (dayOfMonth <= daysInMonth); j++) {
                        String td = "<td>" + String.valueOf(dayOfMonth) + "</td>";
                        if (zi != null) {
                            if(dayOfMonth == Integer.valueOf(zi))
                                if (culoare != null)
                                    td = "<td bgcolor=\"" + culoare + "\">" + String.valueOf(dayOfMonth) + "</td>";
                                else
                                    td = "<td bgcolor=\"red\">" + String.valueOf(dayOfMonth) + "</td>";
                        }

                        out.println(td);
                        dayOfMonth++;
                    }
                    out.println("</tr>");
                    out.println("<tr>");
                }
                out.println("</tr>");
                out.println("</table>");
            }
        }catch(Exception e){e.printStackTrace();}
        return SKIP_BODY;//will not evaluate the body content of the tag
    }
}
