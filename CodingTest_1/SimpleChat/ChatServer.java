// SimpleChat Server
import java.net.*;				
import java.io.*;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.*;
				
public class ChatServer {				
				
	public static void main(String[] args) {			
		try{		
			ServerSocket server = new ServerSocket(10001);	
			System.out.println("Waiting Connections...");	
			HashMap hm = new HashMap();
			List<String> banned =  new ArrayList<>();
			while(true){	
				Socket sock = server.accept();
				ChatThread chatthread = new ChatThread(sock, hm,banned);
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

	private List<String> banned;
	private boolean dummyForBan = false;

	public ChatThread(Socket sock, HashMap hm, List<String> banned){
		this.sock = sock;	
		this.hm = hm;
		this.banned = banned;
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
				//여기서 밴 거를거야 - 최상위
				dummyForBan = false;
				for(String s : banned){
					if(line.contains(s)){
						banMessage();
						dummyForBan = true;
						break;
					}
				}
				if(line.equals("/quit"))
					break;
				if(line.startsWith("/addspam ")) {
					addBannedList(line);
				}else if(line.indexOf("/to ") == 0){
					sendmsg(line);
				} else if (line.equals("/banlist")) {
					printBannedList();
				} else if(!dummyForBan) {
					broadcast(id + " : " + line);
				}
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
		LocalTime now = LocalTime.now();
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
		String formattedNow = now.format(formatter);
		int start = msg.indexOf(" ") +1;			
		int end = msg.indexOf(" ", start);			
		if(end != -1){			
			String to = msg.substring(start, end);		
			String msg2 = msg.substring(end+1);		
			Object obj = hm.get(to);		
			if(obj != null){		
				PrintWriter pw = (PrintWriter)obj;	
				pw.println("["+formattedNow+"] "+id + "'s secret message: " + msg2);
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
	public void banMessage(){
		Object obj = hm.get(id);
		PrintWriter pw = (PrintWriter)obj;
		pw.println("Don't use banned words!");
		pw.flush();
	}
	public void addBannedList(String msg){
		int start = msg.indexOf(" ");
		if(start != -1){
			String msg2 = msg.substring(start+1);
			synchronized(banned){
				banned.add(msg2);
			}
			Object obj = hm.get(id);
			if(obj != null){
				PrintWriter pw = (PrintWriter)obj;
				pw.println("Added a banned word - [" + msg2+"]");
				pw.flush();
			} // if
		}
	}
	public void printBannedList(){
		Object obj = hm.get(id);
		PrintWriter pw = (PrintWriter)obj;

		pw.println("There are "+banned.size()+" words");
		for (String i : banned){
			pw.println(i);
		}
		pw.println();
		pw.flush();
	}
}				
