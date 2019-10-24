
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Problema 6</title>
    <link rel="stylesheet" href="index.css">
    <script>
        window.addEventListener("load", main);

        function main() {
        <% if (session.getAttribute("game_id") == null) { %>
            getGameID();
        <% } else { %>
            document.getElementById("gameDetails").innerHTML = "GameID=" + <% out.print(session.getAttribute("game_id")); %>
            myFunction();
        <% } %>
        }

        function getGameID() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange=function() {
                if (this.readyState == 4 && this.status == 200) {
                    console.log("getting game id");

                    location.reload();
                }
            };
            xhttp.open("GET", "TicTacToe", true);
            xhttp.send();
        }

        function setupCellListeners() {
            for (var i = 0; i < 3; i++) {
                for (var j = 0; j < 3; j++) {
                    document.getElementById(i + '' + j).addEventListener('click', handleCellClick);
                }
            }
        }
        function setCharAt(str,index,chr) {
            if(index > str.length-1) return str;
            return str.substr(0,index) + chr + str.substr(index+1);
        }

        function handleCellClick(event) {
            var element = event.target;
            console.log(element.innerText);
            <%
            //if (session.getAttribute("last_played") != null && session.getAttribute("last_played").equals(session.getAttribute("mark"))) { %>
                //alert("Nu poti face 2 mutari consecutiv!");
           <%--<% } else {%>--%>
                if (element.innerText === "") {
                    element.innerText = '<% out.print(session.getAttribute("mark")); %>';
                    sendNewTable();
                }
                else alert("Miscare invalida!Celula este deja ocupata.")
            <%--<% } %>--%>
        }

        function buildNewTable() {
            var newTable = "_________";
            for (var i = 0; i < 3; i++) {
                for (var j = 0; j < 3; j++) {
                    var valoare = document.getElementById(i + '' + j).innerText;
                    if (valoare === "X" || valoare === "O") {
                        var index = i * 3 + j;
                        newTable = setCharAt(newTable, index, valoare);
                    }
                }
            }
            return newTable;
        }
        function sendNewTable() {
            var newTable = buildNewTable();

            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange=function() {
                if (this.readyState == 4 && this.status == 200) {
                    console.log("sent succesfully!");
                }
            };
            xhttp.open("POST", "TicTacToe", true);
            xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xhttp.send("table=" + newTable);
        }

        function myFunction() {
            setInterval(function(){
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange=function() {
                    if (this.readyState == 4 && this.status == 200) {
                        if (this.responseText === "Still waiting for a worthy oponnent!") {
                            document.getElementById("gameStatus").innerHTML = "Still waiting for an oponnent!";
                        }
                        else {
                            setupCellListeners();
                            document.getElementById("gameStatus").innerHTML = "Game in progress! Enjoy";
                            console.log(this.responseText);

                            //var newTable = JSON.parse(this.responseText).table;
                            var newTable = this.responseText;
                            for (var i = 0; i < newTable.length; i++) {
                                if (newTable[i] !== "_") {
                                    var char = newTable[i];
                                    var linie = Math.floor(i / 3);
                                    var coloana = i % 3;
                                    document.getElementById(linie + '' + coloana).innerText = char;
                                }
                            }

                            getGameStatus();
                        }
                    }
                };
                xhttp.open("GET", "TicTacToe", true);
                xhttp.send();
            }, 2000);
        }

    function getGameStatus() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange=function() {
            if (this.readyState == 4 && this.status == 200) {
                if (this.responseText != "_") {
                    alert(this.responseText + " WON! CONGRATS!");
                    location.reload();
                }
            }
        };
        xhttp.open("GET", "GameStatus", true);
        xhttp.send();
    }
    </script>
</head>
<body>
    <h1>Hello SSE!</h1>
    <div id="gameDetails"></div>
    <div id="gameStatus"></div>

    <table>
        <tr>
            <td id="00"></td>
            <td id="01"></td>
            <td id="02"></td>
        </tr>
        <tr>
            <td id="10"></td>
            <td id="11"></td>
            <td id="12"></td>
        </tr>
        <tr>
            <td id="20"></td>
            <td id="21"></td>
            <td id="22"></td>
        </tr>
    </table>
</body>
</html>
