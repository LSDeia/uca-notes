public class Main {
    public static void main(String[] args) {
        // Vehicles Instances
        Bike b1 = new Bike(2,vehicleType.Bike,"Vélo de tim",false,2,"XVF7-6TYH-GIU8");
        Bike b2 = new Bike(7,vehicleType.Bike,"Vélo de aurian",true,7,"TGYU-666J-777A");
        Trotinette t1 = new Trotinette(4,vehicleType.Trotinette,"Trotinette de nicolas",true,1,160);
        Trotinette t2 = new Trotinette(16,vehicleType.Trotinette,"Trotinette de corentin",false,15,30);

        // Garage Instance
        Garage g1 = new Garage();
        g1.add(b1);
        g1.add(b2);
        g1.add(t1);
        g1.add(t2);

        // Save Garage in file
        SaveCSV.save("haha.csv",g1);
        SaveSerial.save("garage.srl",g1);
    }
}