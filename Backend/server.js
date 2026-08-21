const express = require("express");
const cors = require("cors");
require("dotenv").config();

const Groq = require("groq-sdk");

const app = express();

const PORT = process.env.PORT || 8000;

// Groq client
const groq = new Groq({
    apiKey: process.env.GROQ_API_KEY
});

// Middleware
app.use(cors());
app.use(express.json());

// Home route
app.get("/", (req, res) => {
    res.json({
        message: "AlgoSphere AI Backend is running"
    });
});

// Health check
app.get("/api/health", (req, res) => {
    res.json({
        success: true,
        message: "AlgoSphere AI Backend is healthy"
    });
});

// AI route
app.post("/api/ai", async (req, res) => {
    try {
        const { question } = req.body;

        if (!question) {
            return res.status(400).json({
                success: false,
                message: "Question is required"
            });
        }

        const response = await groq.chat.completions.create({
            model: "openai/gpt-oss-20b",
            messages: [
                {
                    role: "system",
                    content:
                        "You are AlgoSphere AI, an AI DSA interview assistant. Explain DSA concepts clearly, simply, and with examples when useful."
                },
                {
                    role: "user",
                    content: question
                }
            ]
        });

        res.json({
            success: true,
            answer: response.choices[0].message.content
        });

    } catch (error) {
        console.error("AI Error:", error);

        res.status(500).json({
            success: false,
            message: "AI response failed",
            error: error.message
        });
    }
});

// Start server
app.listen(PORT, () => {
    console.log(`AlgoSphere AI Backend running on port ${PORT}`);
});