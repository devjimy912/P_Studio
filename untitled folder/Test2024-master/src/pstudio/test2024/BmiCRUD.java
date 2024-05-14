package pstudio.test2024;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class BmiCRUD implements iCRUD{
    private ArrayList<BmiItem> list;
    public BmiCRUD() {
        this.list = new ArrayList<BmiItem>();
    }

    public void loadData() throws IOException {
        File file = new File("src/data.txt");
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);

        String line;

        while((line = br.readLine()) != null) {
            String[] lines = line.split("/");
            BmiItem item = new BmiItem(lines[0], Integer.valueOf(lines[1]), Integer.valueOf(lines[2]));
            list.add(item);
        }
        br.close();
    }
    @Override
    public Object createItem() {
        return null;
    }

    @Override
    public int addItem() {
        String name;
        int height, weight;
        Scanner sc = new Scanner(System.in);

        System.out.print("Add a new record\n"
                + "Enter your name: ");
        name = sc.nextLine().trim();;

        System.out.print("Enter height and weight: ");
        height = sc.nextInt();;
        weight = sc.nextInt();;

        BmiItem newitem = new BmiItem(name, height, weight);
        this.list.add(newitem);
        System.out.println("Record added.");
        return 0;
    }

    @Override
    public int updateItem() {
        int height, weight;
        Scanner sc = new Scanner(System.in);

        System.out.print("Edit a record\n"
                + "Enter the name to edit: ");
        String name = sc.nextLine().trim();
        BmiItem item_found = findName(name);
        if(item_found == null) {
            System.out.println("Not found.");
            return 1;
        }

        System.out.println(item_found.toString());

        System.out.print("Enter height and weight: ");
        height = sc.nextInt();
        weight = sc.nextInt();
        item_found.setHeight(height);
        item_found.setWeight(weight);
        item_found.resetLevel();
        item_found.setReg_date(new Date());

        System.out.println(item_found.toString());
        System.out.println("Record updated.");
        return 0;
    }

    @Override
    public int deleteItem() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Delete a record\n"
                + "Enter the name to remove: ");
        String name = sc.nextLine().trim();

        BmiItem item_found = findName(name);
        if(item_found == null) {
            System.out.println("Not found.");
            return 1;
        }

        System.out.println(item_found.toString());

        this.list.remove(item_found);
        System.out.println("Record deleted.");
        return 0;
    }

    public BmiItem findName(String name){
        for (BmiItem item : this.list) {
            if (item.getName().equals(name))
                return item;
        }
        return null;

    }

    @Override
    public int printItem() {
        return 0;
    }

    public int printAll() {
        //여기서 정렬 방식 물어봐야함.
        Scanner sc = new Scanner(System.in);
        int sortby;

        System.out.print("sort by [1]name, [2]bmi > ");
        sortby = sc.nextInt();

        if(sortby == 1) {
            sortByName();
        }else if(sortby == 2) {
            sortByBmi();
        }

        System.out.println("Total " + this.list.size() + " records");
        for (BmiItem item : this.list) {
            System.out.println(item.toString());
        }

        return 0;
    }
    public void sortByBmi() {
        Collections.sort(this.list, new BmiItemBmiComparator());
    }

    public void sortByName() {
        Collections.sort(this.list, new BmiItemNameComparator());
    }

    public void reverseList() {
        Collections.reverse(this.list);
    }

    public void report(){
        int UnderweightCount=0;
        int UnderweightSum=0;
        int HeavyweightCount=0;
        int HeavyweightSum=0;
        int OverweightCount=0;
        int OverweightSum=0;
        int ObesityCount=0;
        int ObesitySum=0;

        System.out.println("Total " + this.list.size() + " records");
        for (BmiItem item : this.list) {
            if(item.getLevel().equals("Underweight")){
                UnderweightCount++;
                UnderweightSum+=item.getWeight();
            }else if(item.getLevel().equals("Healthy Weight")){
                HeavyweightCount++;
                HeavyweightSum+=item.getWeight();
            }else if(item.getLevel().equals("Overweight")){
                OverweightCount++;
                OverweightSum+=item.getWeight();
            }else if(item.getLevel().equals("Obesity")){
                ObesityCount++;
                ObesitySum+=item.getWeight();
            }
        }
//        System.out.println(String.format("%f_", 3.4));
        System.out.println("Underweight - " + UnderweightCount+ " (average "+String.format("%.1f",UnderweightSum*1.0/UnderweightCount)+")");
        System.out.println("Healthy Weight - " + HeavyweightCount+" (average "+String.format("%.1f",HeavyweightSum*1.0/HeavyweightCount)+")");
        System.out.println("Overweight - " + OverweightCount+" (average "+String.format("%.1f",OverweightSum*1.0/OverweightCount)+")");
        System.out.println("Obesity - " + ObesityCount+" (average "+String.format("%.1f",ObesitySum*1.0/ObesityCount)+")");
    }
    public void save(){
        String fileName = "src"+File.separator+"data.txt";
        File file = new File(fileName);

        try (
                FileOutputStream fileOutputStream = new FileOutputStream(fileName);
                OutputStreamWriter outputStreamWriter = new OutputStreamWriter(fileOutputStream, StandardCharsets.UTF_8);
//                BufferedWriter bw = new BufferedWriter(outputStreamWriter);
        ) {
            String data;
            for(BmiItem item : this.list){
                data = item.getName()+"/"+item.getHeight()+"/"+item.getWeight()+System.lineSeparator();
                outputStreamWriter.write(data);
            }
            System.out.println("save finished.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


class BmiItemBmiComparator implements Comparator<BmiItem> {
    @Override
    public int compare(BmiItem o1, BmiItem o2) {
        if (o1.getBmi() < o2.getBmi())
            return -1;
        else
            return 1;
    }
}
class BmiItemNameComparator implements Comparator<BmiItem> {
    @Override
    public int compare(BmiItem o1, BmiItem o2) {
        return o1.getName().compareTo(o2.getName());
    }
}
