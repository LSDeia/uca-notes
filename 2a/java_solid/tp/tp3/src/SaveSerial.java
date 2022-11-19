import java.io.*;

public class SaveSerial {
    static public void save(String filename, Garage g){
        try {
            FileOutputStream file = new FileOutputStream(filename);
            ObjectOutputStream out = new ObjectOutputStream(file);
            for (Vehicle v : g.vehicleList) {
                out.writeObject(v);
            }
            out.close();
            file.close();
        } catch (IOException e){
            System.out.println("Problem when writing to file!");
        }
    }
}
