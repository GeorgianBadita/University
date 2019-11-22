import React, { Component } from 'react';
import { View, TextInput, Button, Text} from 'react-native';

import { getLogger, navService } from '../core';
import { ItemContext } from "./ItemContext";

const log = getLogger('ItemEdit');

export const ItemEdit = ({text = '', navigation }) => {
  const [productname, setProductName] = React.useState(text);
  const [priceProd, setPrice] = React.useState(text);

  return (
      <ItemContext.Consumer>
        {({ onSubmit }) => (
            <View>
              <Text>Product Name: </Text>
              <TextInput
                  style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
                  onChangeText={text => setProductName(text)}
                  productname={productname}
              />
              
              <Text>Price: </Text>
              <TextInput
                  style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
                  onChangeText={text => setPrice(text)}
                  priceProd={priceProd}

              />
              <Button
                  title="Submit"
                  onPress={() => {
                    log(productname);
                    var price = parseInt(priceProd)
                    onSubmit({productname, price})
                        .then(() => navigation.goBack())
                  }}
              />
            </View>
        )}
      </ItemContext.Consumer>
  );
};

ItemEdit.navigationOptions = () => ({
  headerTitle: 'Item Edit',
});
