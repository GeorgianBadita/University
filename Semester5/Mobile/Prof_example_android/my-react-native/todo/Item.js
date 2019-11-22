import React from 'react';
import {StyleSheet, Text, View} from 'react-native';

import { getLogger } from '../core';

const log = getLogger('Item');

export default ({ item = {} }) => {
  log('render');
  return (
      <View style={home_screen_list.row} flexDirection='column'>
        <View><Text>Name: {item.productname}</Text></View>
        <View><Text>Price: {item.price}</Text></View>
      </View>
  );
};


export const home_screen_list = StyleSheet.create(
  {
    container: {
      marginTop: 14,
      alignSelf: "stretch",
    },
    row: {
      elevation: 1,
      borderRadius: 2,
      flex: 1,
      flexDirection: 'row',  // main axis
      justifyContent: 'flex-start', // main axis
      alignItems: 'center', // cross axis
      paddingTop: 10,
      paddingBottom: 10,
      paddingLeft: 18,
      paddingRight: 16,
      marginLeft: 14,
      marginRight: 14,
      marginTop: 0,
      marginBottom: 6,
    },
   
  });