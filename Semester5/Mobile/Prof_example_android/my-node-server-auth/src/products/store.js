import dataStore from 'nedb-promise';

export class NoteStore {
  constructor({ filename, autoload }) {
    this.store = dataStore({ filename, autoload });
  }
  
  async find(props) {
    return this.store.find(props);
  }
  
  async findOne(props) {
    return this.store.findOne(props);
  }
  
  async insert(product) {

    return this.store.insert(product);
  };
  
  async update(props, product) {
    return this.store.update(props, product);
  }
  
  async remove(props) {
    return this.store.remove(props);
  }
}

export default new NoteStore({ filename: './db/products.json', autoload: true });