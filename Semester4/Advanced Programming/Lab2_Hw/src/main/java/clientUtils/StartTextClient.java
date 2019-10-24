package clientUtils;

import java.net.Socket;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class StartTextClient {
    public static void main(String[] args) {
        System.out.println("Trying to connect ...");
        try(Socket client=new Socket("localhost",55555)) {
            System.out.println("Connection obtained.");
            try(PrintWriter writer=new PrintWriter(client.getOutputStream());
                BufferedReader br=new BufferedReader(new InputStreamReader(client.getInputStream()))) {
                Scanner scan = new Scanner(System.in);
                String username, pass;


                System.out.println("Username...");
                username = scan.nextLine();
                System.out.println("Password...");
                pass = scan.nextLine();
                String user = username + " " + pass;

                writer.println(user);
                writer.flush();

                System.out.println("Waiting for response...");
                String response = br.readLine();
                System.out.println("Response: " + response);


            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
