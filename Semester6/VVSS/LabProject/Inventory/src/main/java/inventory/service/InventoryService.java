package inventory.service;

import inventory.model.*;
import inventory.repository.InventoryRepository;
import javafx.collections.ObservableList;

public class InventoryService {

    private InventoryRepository repo;

    public InventoryService(InventoryRepository repo){
        this.repo =repo;
    }


    public void addInhousePart(String name, double price, int inStock, int min, int  max, int partDynamicValue){
        InhousePart inhousePart = new InhousePart(repo.getAutoPartId(), name, price, inStock, min, max, partDynamicValue);
        repo.addPart(inhousePart);
    }

    public void addOutsourcePart(String name, double price, int inStock, int min, int  max, String partDynamicValue){
        OutsourcedPart outsourcedPart = new OutsourcedPart(repo.getAutoPartId(), name, price, inStock, min, max, partDynamicValue);
        repo.addPart(outsourcedPart);
    }

    public void addProduct(String name, double price, int inStock, int min, int  max, ObservableList<Part> addParts){
        Product product = new Product(repo.getAutoProductId(), name, price, inStock, min, max, addParts);
        repo.addProduct(product);
    }

    public ObservableList<Part> getAllParts() {
        return repo.getAllParts();
    }

    public ObservableList<Product> getAllProducts() {
        return repo.getAllProducts();
    }

    public Part lookupPart(String search) {
        return repo.lookupPart(search);
    }

    public Product lookupProduct(String search) {
        return repo.lookupProduct(search);
    }

    public void updateInhousePart(int partIndex, int partId, String name, double price, int inStock, int min, int max, int partDynamicValue){
        InhousePart inhousePart = new InhousePart(partId, name, price, inStock, min, max, partDynamicValue);
        repo.updatePart(partIndex, inhousePart);
    }

    public void updateOutsourcedPart(int partIndex, int partId, String name, double price, int inStock, int min, int max, String partDynamicValue){
        OutsourcedPart outsourcedPart = new OutsourcedPart(partId, name, price, inStock, min, max, partDynamicValue);
        repo.updatePart(partIndex, outsourcedPart);
    }

    public void updateProduct(int productIndex, int productId, String name, double price, int inStock, int min, int max, ObservableList<Part> addParts){
        Product product = new Product(productId, name, price, inStock, min, max, addParts);
        repo.updateProduct(productIndex, product);
    }

    public void deletePart(Part part){
        repo.deletePart(part);
    }

    public void deleteProduct(Product product){
        repo.deleteProduct(product);
    }

}
