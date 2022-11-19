import javax.imageio.IIOException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class SaveCSV implements ISaver{

    static void save(String filename, Garage g){
        try {
            // Create FileWriter with filename
            FileWriter file = new FileWriter(filename);
            // Loop to write all vehicles
            file.write("id,type,name,motor,nbPassenger,[speed/serialNumber]\n");
            for (Vehicle v : g.vehicleList) {
                file.write(v.toCSV());
                System.out.println(v.toCSV());
            }
            file.close();
        } catch (IOException e){
            System.out.println("Problem when writing to file!");
        }
    }
}
