public class Bike extends Vehicle{
    String serialNumber;

    Bike(int id, vehicleType type, String name,boolean motor,int nbPassenger,String serialNumber ){
        super(id, type, name, motor, nbPassenger);
        this.serialNumber = serialNumber;
    };

    @Override
    String toCSV() {
        return this.id + "," + this.type + "," + this.name + "," + this.motor + "," + this.nbPassenger + "," + this.serialNumber + "\n";
    }

    @Override
    public String toString() {
        return toCSV();
    }
}
