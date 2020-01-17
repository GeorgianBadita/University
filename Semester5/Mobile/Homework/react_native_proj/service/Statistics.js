import React, { useEffect, useLayoutEffect } from 'react';
import {View, Text, AsyncStorage, StyleSheet, UIManager, Platform, TouchableOpacity} from 'react-native';
import {ONLINE_ITEMS, OFFLINE_ITEMS} from './CityIssueStore'
import {PieChart} from "react-native-chart-kit";
import {stringifyValueWithProperty} from "react-native-web/dist/exports/StyleSheet/compile";
import {LayoutAnimation} from "react-native-web";

if (Platform.OS === 'android') {
    if (UIManager.setLayoutAnimationEnabledExperimental) {
        UIManager.setLayoutAnimationEnabledExperimental(true);
    }
}

export const Statistics = () => {
    const [state, setState] = React.useState({
        items1:0,
        items2:0,
        items3:0,
        items4:0,
        items5:0
    });
    const {items1, items2, items3, items4, items5} = state;
    useEffect(() =>{
        console.log("ENTER USE EFFECTS")
        let ok=false;
        AsyncStorage.getItem(ONLINE_ITEMS).then( x=> {
            var online_items_list = JSON.parse(x);
            AsyncStorage.getItem(OFFLINE_ITEMS).then(x => {
                var offline_items_list = JSON.parse(x);
                var all = Object.assign({}, online_items_list, offline_items_list);
                var arr = [];
                var c1=0,c2=0,c3=0,c4=0,c5=0;
                for (var key in all) {
                    var el = all[key];
                    console.log(JSON.stringify(el))
                    if (el.severity === "1"){
                        c1++;
                    }
                    if (el.severity === "2"){
                        c2++;
                    }
                    if (el.severity === "3"){
                        c3++;
                    }
                    if (el.severity === "4"){
                        c4++;
                    }
                    if (el.severity === "5"){
                        c5++;

                    }
                }
                console.log(c1)
                console.log(c2)
                console.log(c3)
                console.log(c4)
                console.log(c5)
                LayoutAnimation.spring();
                setState({
                    items1: c1,
                    items2: c2,
                    items3: c3,
                    items4: c4,
                    items5: c5
                })
                    ok=false
            });
        });
        return ()=>{
        }
    },[]);

    return(
        <View>
            <PieChart
                data={[
                    {
                        name: 'Severity 1',
                        population: items1,
                        color: 'rgba(131, 167, 234, 1)',
                        legendFontColor: '#7F7F7F',
                        legendFontSize: 15,
                    },
                    {
                        name: 'Severity 2',
                        population: items2,
                        color: '#55ff4c',
                        legendFontColor: '#7F7F7F',
                        legendFontSize: 15,
                    },
                    {
                        name: 'Severity 3',
                        population: items3,
                        color: '#edff18',
                        legendFontColor: '#7F7F7F',
                        legendFontSize: 15,
                    },
                    {
                        name: 'Severity 4',
                        population: items4,
                        color: 'rgb(255,30,38)',
                        legendFontColor: '#7F7F7F',
                        legendFontSize: 15,
                    },
                    {
                        name: 'Severity 5',
                        population: items5,
                        color: 'rgb(18,0,1)',
                        legendFontColor: '#7F7F7F',
                        legendFontSize: 15,
                    },
                ]}
                width={300}
                height={220}
                chartConfig={{
                    backgroundColor: '#1cc910',
                    backgroundGradientFrom: '#eff3ff',
                    backgroundGradientTo: '#efefef',
                    decimalPlaces: 2,
                    color: (opacity = 1) => `rgba(0, 0, 0, ${opacity})`,
                    style: {
                        borderRadius: 16,
                    },
                }}
                style={{
                    marginVertical: 8,
                    borderRadius: 16,
                }}
                accessor="population"
                backgroundColor="transparent"
                paddingLeft="15"
                absolute //for the absolute number remove if you want percentage
            />
        </View>

    )
};

PieChart.navigationOptions = () => ({
    headerTitle:"Statistics"
});

