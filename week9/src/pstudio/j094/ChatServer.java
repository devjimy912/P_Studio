package pstudio.j094;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;

public class ChatServer {

    public static void main(String[] args) {
        try{
            ServerSocket server = new ServerSocket(10001);
            System.out.println("Waiting Connections...");
            HashMap hm = new HashMap();
            while(true){
                Socket sock = server.accept();
                ChatThread chatthread = new ChatThread(sock, hm);
                chatthread.start();
            } // while
        }catch(Exception e){
            System.out.println(e);
        }
    } // main
}

class ChatThread extends Thread{
    private Socket sock;
    private String id;
    private BufferedReader br;
    private HashMap hm;
    private boolean initFlag = false;
    public ChatThread(Socket sock, HashMap hm){
        this.sock = sock;
        this.hm = hm;
        try{
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(sock.getOutputStream()));
            br = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            id = br.readLine();
            broadcast(id + " entered.");
            System.out.println("[Server log] " + id + " entered.");
            synchronized(hm){
                hm.put(this.id, pw);
            }
            initFlag = true;
        }catch(Exception ex){
            System.out.println(ex);
        }
    }
    public void run(){
        try{
            String line = null;
            while((line = br.readLine()) != null){
                if(line.equals("/quit"))
                    break;
                if(line.indexOf("/to ") == 0){
                    sendmsg(line);
                } else if (line.indexOf("/userlist") == 0) {
                    userlist();
                } else
                    broadcast(id + " : " + line);
            }
        }catch(Exception ex){
            System.out.println(ex);
        }finally{
            synchronized(hm){
                hm.remove(id);
            }
            broadcast(id + " exited.");
            System.out.println("[Server log] " + id + " exited.");
            try{
                if(sock != null)
                    sock.close();
            }catch(Exception ex){}
        }
    } // run
    public void sendmsg(String msg){
        int start = msg.indexOf(" ") +1;
        int end = msg.indexOf(" ", start);
        if(end != -1){
            String to = msg.substring(start, end);
            String msg2 = msg.substring(end+1);
            Object obj = hm.get(to);
            if(obj != null){
                PrintWriter pw = (PrintWriter)obj;
                pw.println(id + "'s secret message: " + msg2);
                pw.flush();
            } // if
        }
    } // sendmsg
    public void broadcast(String msg){
        LocalTime now = LocalTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
        String formattedNow = now.format(formatter);
        synchronized(hm){
            Collection collection = hm.values();
            Iterator iter = collection.iterator();
            while(iter.hasNext()){
                PrintWriter pw = (PrintWriter)iter.next();
                pw.println("["+formattedNow+"] "+msg);
                pw.flush();
            }
        }
    } // broadcast
    public void userlist(){
        Object obj = hm.get(id);
        PrintWriter pw = (PrintWriter)obj;

        pw.println("There are "+hm.size()+" users");
        for(Iterator<String> it = hm.keySet().iterator(); it.hasNext();){
            pw.print(it.next());
            if(it.hasNext()){
                pw.print(", ");
            }
        }
        pw.println();
        pw.flush();
    }// userlist
}
