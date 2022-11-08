public class Main {

    public static void main(String[] args) {
        Farm farm = new Farm();
        boolean loop = true;
        while (loop) {
            Display.menu();
            int res = Input.enterMenu();
            switch (res) {
                case 1:
                    Chipmunk chipmunk = Input.enterChipmunk();
                    farm.add(chipmunk);
                    break;
                case 2:
                    Kangaroo kangaroo = Input.enterKangaroo();
                    farm.add(kangaroo);
                    break;
                case 3:
                    Display.farm(farm.farmList);
                    break;
                case 4:
                    farm.switchAllToWinter();
                    break;
                default:
                    System.out.println("End of Program");
                    return;
            }
        }
    }
}