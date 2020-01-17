import { getLogger } from "../core";
import React, { useState, useContext, useEffect, useCallback } from "react";
import { View, StyleSheet, ActivityIndicator, Dimensions } from 'react-native';
import { CityIssueContext } from './CityIssueContext';
import MapView from 'react-native-maps';
import {findCurrentLocation} from "../core/location";

const { height, width } = Dimensions.get( 'window' );
const LATITUDE_DELTA = 0.005;
const LONGITUDE_DELTA = LATITUDE_DELTA * (width / height);
const log = getLogger('IssueMap');

const initialState = {
    latitude: 0,
    longitude: 0,
    isLoading: true
};

export const IssueMap = () => {
    log('render');
    const [state, setState] = useState(initialState);
    const {latitude, longitude, isLoading} = state;
    useEffect(() => {
        log('didMount');
        if (state.isLoading)
            getCurrentLocation()
                .then(coordinate => {
                    log(coordinate);
                    const {latitude, longitude} = coordinate;
                    setState({latitude,longitude,isLoading: false});
                });
        return () => {
            log('willUnmount');
        }
    }, []);

    const getCurrentLocation = useCallback(async () => {
        log('getCurrentLocation started...');
        return findCurrentLocation()
            .then(location => {
                log('getCurrentLocation finished...');
                log(location);
                const {latitude,longitude} = location.coords;
                return Promise.resolve({latitude,longitude});
            });
    });
    return (
        <View style ={styles.container}>
            <ActivityIndicator animating = {isLoading} size = 'large'/>
            {!isLoading && <MapView
                style={styles.map}
                initialRegion = {{
                    latitude: latitude,
                    longitude: longitude,
                    latitudeDelta: LATITUDE_DELTA,
                    longitudeDelta: LONGITUDE_DELTA
                }}

                showsUserLocation={true}
            />}
        </View>
    )
};

IssueMap.navigationOptions = () => ({
    headerTitle:"Location"
});

const styles = StyleSheet.create({
    container: {
        position: 'absolute',
        top: 0,
        left: 0,
        right: 0,
        bottom: 0,
        justifyContent: 'flex-end',
        alignItems: 'center',
    },
    map: {
        position: 'absolute',
        top: 0,
        left: 0,
        right: 0,
        bottom: 0,
    },
});
