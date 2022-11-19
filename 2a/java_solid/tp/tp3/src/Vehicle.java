import java.io.Serializable;

enum vehicleType{
    Trotinette,
    Bike
}

public abstract class Vehicle implements Serializable {
    int id;
    vehicleType type;
    String name;
    boolean motor;
    int nbPassenger;

    Vehicle(int id, vehicleType type, String name, boolean motor, int nbPassenger){
        this.id = id;
        this.type = type;
        this.name = name;
        this.motor = motor;
        this.nbPassenger = nbPassenger;
    }

    abstract String toCSV();
}
