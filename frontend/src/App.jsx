import { useState } from "react";
import "./App.css";

const API_URL = "https://algosphereai.onrender.com/api/ai";

function App() {
  const [question, setQuestion] = useState("");
  const [answer, setAnswer] = useState("");
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");

  const askAI = async () => {
    if (!question.trim()) {
      setError("Please enter a DSA question.");
      return;
    }

    setLoading(true);
    setAnswer("");
    setError("");

    try {
      const response = await fetch(API_URL, {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({
          question: question.trim(),
        }),
      });

      const data = await response.json();

      if (!response.ok) {
        throw new Error(data.message || "AI request failed");
      }

      setAnswer(data.answer);
    } catch (err) {
      setError(err.message || "Something went wrong.");
    } finally {
      setLoading(false);
    }
  };

  return (
    <main className="app">
      <div className="container">
        <header className="header">
          <div className="logo">⚡</div>

          <div>
            <h1>AlgoSphere AI</h1>
            <p>Intelligent DSA Learning & AI Assistant</p>
          </div>
        </header>

        <section className="hero">
          <h2>Ask Anything About DSA</h2>

          <p>
            Learn Data Structures and Algorithms with an
            AI-powered assistant.
          </p>

          <textarea
            value={question}
            onChange={(e) => setQuestion(e.target.value)}
            placeholder="Example: Explain binary search with a C++ example..."
          />

          <button onClick={askAI} disabled={loading}>
            {loading ? "Thinking..." : "Ask AlgoSphere AI"}
          </button>

          {error && <div className="error">{error}</div>}
        </section>

        {answer && (
          <section className="answer-section">
            <h2>🤖 AI Response</h2>

            <div className="answer">
              {answer}
            </div>
          </section>
        )}

        <section className="features">
          <div className="feature">
            <h3>📚 DSA Learning</h3>
            <p>
              Understand arrays, searching, sorting,
              linked lists, trees, graphs and more.
            </p>
          </div>

          <div className="feature">
            <h3>💡 AI Assistant</h3>
            <p>
              Ask DSA questions and receive explanations,
              examples and solutions.
            </p>
          </div>

          <div className="feature">
            <h3>💻 C++ Focused</h3>
            <p>
              Get programming examples and solutions in C++.
            </p>
          </div>
        </section>

        <footer>
          <p>AlgoSphere AI • DSA + AI Assistant</p>
        </footer>
      </div>
    </main>
  );
}

export default App;