
package inventory.model;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;


public class Product {
    
    // Declare fields
    private ObservableList<Part> associatedParts;// = FXCollections.observableArrayList();
    private int productId;
    private String name;
    private double price;
    private int inStock;
    private int min;
    private int max;

    // Constructor
    public Product(int productId, String name, double price, int inStock, int min, int max, ObservableList<Part> partList) {
        this.productId = productId;
        this.name = name;
        this.price = price;
        this.inStock = inStock;
        this.min = min;
        this.max = max;
        this.associatedParts= partList;
    }
    
    // Getters
    public ObservableList<Part> getAssociatedParts() {
        return associatedParts;
    }

    public int getProductId() {
        return productId;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public int getInStock() {
        return inStock;
    }

    public int getMin() {
        return min;
    }

    public int getMax() {
        return max;
    }
    
    // Setters
    public void setAssociatedParts(ObservableList<Part> associatedParts) {
        associatedParts = associatedParts;
    }

    public void setProductId(int productId) {
        this.productId = productId;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setInStock(int inStock) {
        this.inStock = inStock;
    }

    public void setMin(int min) {
        this.min = min;
    }

    public void setMax(int max) {
        this.max = max;
    }
    
    // Other methods
    public void addAssociatedPart(Part part) {
        associatedParts.add(part);
    }
    
    public void removeAssociatedPart(Part part) {
        associatedParts.remove(part);
    }
    
    public Part lookupAssociatedPart(String searchItem) {
        for(Part p:associatedParts) {
            if(p.getName().contains(searchItem) || new Integer(p.getPartId()).toString().equals(searchItem)) return p;
        }
        return null;
    }
    
    /**
     * Generate an error message for invalid values in a product
     * and evaluate whether the sum of the price of associated parts
     * is less than the price of the resulting product.
     * A valid product will return an empty error message string.
     * @param name
     * @param min
     * @param max
     * @param inStock
     * @param price
     * @param parts
     * @param errorMessage
     * @return 
     */
    public static String isValidProduct(String name, double price, int inStock, int min, int max, ObservableList<Part> parts, String errorMessage) {
        double sumOfParts = 0.00;
        for (int i = 0; i < parts.size(); i++) {
            sumOfParts += parts.get(i).getPrice();
        }
        if (name.equals("")) {
            errorMessage += "A name has not been entered. ";
        }
        if (min < 0) {
            errorMessage += "The inventory level must be greater than 0. ";
        }
        if (price < 0.01) {
            errorMessage += "The price must be greater than $0. ";
        }
        if (min > max) {
            errorMessage += "The Min value must be less than the Max value. ";
        }
        if(inStock < min) {
            errorMessage += "Inventory level is lower than minimum value. ";
        }
        if(inStock > max) {
            errorMessage += "Inventory level is higher than the maximum value. ";
        }
        if (parts.size() < 1) {
            errorMessage += "Product must contain at least 1 part. ";
        }
        if (sumOfParts > price) {
            errorMessage += "Product price must be greater than cost of parts. ";
        }
        return errorMessage;
    }

    @Override
    public String toString() {
        return "P,"+this.productId+","+this.name+","+this.price+","+this.inStock+","+
                this.min+","+this.max;
    }
}
