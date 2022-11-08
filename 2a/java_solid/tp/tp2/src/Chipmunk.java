public class Chipmunk extends Animal{

    int nbOfSeeds = 0;
    String fur = "short";

    Chipmunk(String name, String dateOfBirth, int nbOfSeeds) {
        super(name, dateOfBirth);
        this.nbOfSeeds = nbOfSeeds;
    }

    @Override
    public void switchToWinter(){
        this.fur = "long";
        this.nbOfSeeds += 10;
        this.health -= 30;
        System.out.println("[Chipmunk " + this.name + "] my fur is long now and i have 10 more seeds!");
    }

    @Override
    public String toString(){
        return "Name: " + this.name + ", Birth: " + this.dateOfBirth +
                "\nSeeds: " + this.nbOfSeeds + ", Fur: " + this.fur;
    }
}
