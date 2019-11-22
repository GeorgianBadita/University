import React, { useContext } from 'react';
import { ActivityIndicator, Button, FlatList, Text, View } from 'react-native';

import { getLogger, navService } from '../core';
import { ItemContext } from './ItemContext';
import { AuthContext } from '../auth/AuthContext';
import Item from './Item';

const log = getLogger('ItemList');

export const ItemList = ({ navigation }) => {
  log('render');
  const { onSignOut } = useContext(AuthContext);
  return (
    <View>
      <ItemContext.Consumer>
        {({ isLoading, loadingError, items }) => (
          <View>
            <ActivityIndicator animating={!!isLoading} size="large"/>
            {loadingError && <Text>{loadingError.message || 'Loading error'}</Text>}
            {items && 
              <FlatList
                data={items.map(item => ({ ...item, key: item.id }))}
                renderItem={({ item }) => <Item item={item}/>}
              />}
          </View>
        )}
      </ItemContext.Consumer>
      <Button
        onPress={() => onSignOut().then(() => navigation.navigate('Auth'))}
        title="Sign Out"
      />
    </View>
  )
};

ItemList.navigationOptions = {
  headerTitle: 'Item List',
  headerRight: (
    <Button
      onPress={() => navService.navigate('ItemEdit')}
      title="Add"
    />
  ),
};

