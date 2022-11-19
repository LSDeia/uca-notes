public class Trotinette extends Vehicle{
    int speed;

    Trotinette(int id, vehicleType type, String name, boolean motor, int nbPassenger, int speed){
        super(id, type, name, motor, nbPassenger);
        this.speed = speed;
    }

    @Override
    public String toCSV() {
        return this.id + "," + this.type + "," + this.name + "," + this.motor + "," + this.nbPassenger + "," + this.speed + "\n";
    }

    @Override
    public String toString() {
        return toCSV();
    }
}
