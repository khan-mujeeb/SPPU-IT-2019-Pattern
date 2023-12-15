const express = require("express")

const app = express()

app.get("/", (req, res) => {
    res.sendFile(__dirname + '/index.html')
})

app.listen(3000, () => {
    console.log("server start at port 3000")
})