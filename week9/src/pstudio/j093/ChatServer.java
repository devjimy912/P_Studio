package pstudio.j093;

import java.net.*;
import java.io.*;
import java.util.*;

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
                } else if (line.equals("/userlist")) {
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
        synchronized(hm){
            Collection collection = hm.values();
            Iterator iter = collection.iterator();
            while(iter.hasNext()){
                PrintWriter pw = (PrintWriter)iter.next();
                pw.println(msg);
                pw.flush();
            }
        }
    } // broadcast
    public void userlist(){
        Object obj = hm.get(id); //리스트 출력할 사람? 위치
        PrintWriter pw = (PrintWriter)obj; //위에서 받은거 출력하기 위한 버퍼

        pw.println("There are "+hm.size()+" users"); // 접속 중인 사람 수
        for(Iterator<String> it = hm.keySet().iterator(); it.hasNext();){ // 유저 id 출력하려고 해쉬맵에서 key값을 하나씩 가져옴
            pw.print(it.next());//다음. 처음에 아무것도 가리키고 있지 않아서 먼저해줘야함. 그리고 아이디 출력
            if(it.hasNext()){//다음이 있으면 , 출력해줌.
                pw.print(", ");
            }
        }
        pw.println();//이건 다 출력하고 나서 줄바꿈해주는거
        pw.flush();//버퍼에 남은거 지우기용.
    }// userlist
}
