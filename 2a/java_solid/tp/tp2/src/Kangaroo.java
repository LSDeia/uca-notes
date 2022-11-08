public class Kangaroo extends Animal{

    int nbUppercut = 0;
    boolean furious = true;

    Kangaroo(String name, String dateOfBirth, int nbUppercut) {
        super(name, dateOfBirth);
        this.nbUppercut = nbUppercut;
    }

    @Override
    public void switchToWinter(){
        this.furious = false;
        this.health -= 10;
        System.out.println("[Kangaroo " + this.name + "] is now calm!");
    }

    @Override
    public String toString(){
        return "Name: " + this.name + ", Birth: " + this.dateOfBirth +
                "\nUppercut: " + this.nbUppercut + ", Furious: " + this.furious;
    }
}
