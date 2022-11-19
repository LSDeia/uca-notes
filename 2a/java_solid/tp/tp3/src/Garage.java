import java.util.ArrayList;
import java.util.List;

public class Garage {
    List<Vehicle> vehicleList;

    Garage(){
        this.vehicleList = new ArrayList<Vehicle>();
    }

    void add(Vehicle v){
        this.vehicleList.add(v);
    }

    void remove(Vehicle v){
        this.vehicleList.remove(v);
    }
}
