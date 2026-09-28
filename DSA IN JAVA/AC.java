public class AC {
    String brand;
    int cost;
    int temperature;
    String rating;

    void brand() {
        System.out.println("Brand: " + brand);
    }

    void cost() {
        System.out.println("Cost: " + cost);
    }

    void temperature() {
        System.out.println("Temperature: " + temperature);
    }

    void rating() {
        System.out.println("Rating: " + rating);
    }

    public static void main(String[] args) {
        AC ac1 = new AC();
        ac1.brand = "Voltas";
        ac1.cost = 30000;
        ac1.temperature = 18;
        ac1.rating = "5 Star";

        ac1.brand();
        ac1.cost();
        ac1.temperature();
        ac1.rating();
    }
}