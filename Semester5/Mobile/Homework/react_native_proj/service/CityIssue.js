import { Text, Animated, View } from 'react-native';
import React, { useEffect } from 'react';
import { getLogger } from '../core';

const log = getLogger('Item');

export default ({ item = {} }) => {
    [state, setState] = React.useState({
        fadeAnim: new Animated.Value(0)
    });
    const {fadeAnim} = state;
    useEffect(()=>{
        Animated.timing(
            fadeAnim,
            {toValue: 1,
            duration: 5000}
        ).start();
    },[]);
  return (
      <Animated.View style = {{
          opacity: fadeAnim,
          borderStyle: 'solid',
          borderColor: '#ABCD33',
          borderWidth: 2
      }}>
        <Text>Description: </Text>
          <Text>{item.issueDescription}</Text>
        <Text>Solution: </Text>
          <Text>{item.solution}</Text>
        <Text>Severity: </Text>
          <Text>{item.severity}</Text>
      </Animated.View>
  );
};
