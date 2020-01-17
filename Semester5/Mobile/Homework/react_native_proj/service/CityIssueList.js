import React, { useContext } from 'react';
import { ActivityIndicator, Button, FlatList, Text, View, ScrollView, StyleSheet } from 'react-native';
import { Pie } from 'react-native-pie'
import { getLogger, navService } from '../core';
import { CityIssueContext } from './CityIssueContext';
import { AuthContext } from '../auth/AuthContext';

import Item from './CityIssue';

const log = getLogger('CityIssueList');

export const CityIssueList = ({ navigation }) => {
  log('render');
  const { onSignOut } = useContext(AuthContext);
  return (
    <ScrollView>
      <CityIssueContext.Consumer>
        {({ isLoading, loadingError, items }) => (
          <View>

            <ActivityIndicator animating={!!isLoading} size="large"/>
            {loadingError && <Text>{loadingError.message || 'Loading error'}</Text>}
            {items &&
              <FlatList
                data={items.map(item => ({ ...item, key: item.id }))}
                renderItem={({ item }) => <Item item={item}/>}
                keyExtractor={(item, index) => index.toString()}
              />}
          </View>
        )}
      </CityIssueContext.Consumer>
      <Button
        onPress={() => onSignOut().then(() => navigation.navigate('Auth'))}
        title="Sign Out"
      />
    </ScrollView>
  )
};

const styles = StyleSheet.create({
    container: {
        flex: 1,
        flexDirection: 'row',
        alignItems: 'center',
        justifyContent: 'center',
    }
});

CityIssueList.navigationOptions = {
  headerTitle: 'Item List',
  headerRight: (
      <View style={styles.container}>
          <Button
              onPress = {() => navService.navigate('IssueMap')}
              title="Map"
          />
          <Button
              onPress = {() => navService.navigate('Statistics')}
              title="Statistics"
          />
          <Button
              onPress = {() => navService.navigate('ItemEdit')}
              title="Add"
          />
      </View>
  ),
};



