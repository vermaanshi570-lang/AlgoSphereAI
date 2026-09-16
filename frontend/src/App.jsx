import { useState } from "react";
import "./App.css";

const API_URL = "https://algosphereai.onrender.com/api/ai";

const topics = [
  {
    icon: "▣",
    title: "Arrays",
    text: "Master traversal, manipulation and common array patterns.",
  },
  {
    icon: "⌁",
    title: "Searching",
    text: "Learn linear search, binary search and optimization techniques.",
  },
  {
    icon: "↗",
    title: "Sorting",
    text: "Understand sorting algorithms and their complexities.",
  },
  {
    icon: "◎",
    title: "Linked Lists",
    text: "Build strong concepts around nodes, pointers and operations.",
  },
  {
    icon: "◇",
    title: "Trees & Graphs",
    text: "Explore traversals, trees, graphs and problem-solving patterns.",
  },
  {
    icon: "#",
    title: "Dynamic Programming",
    text: "Break complex problems into smaller reusable states.",
  },
];

function App() {
  const [question, setQuestion] = useState("");
  const [answer, setAnswer] = useState("");
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");

  const askAI = async () => {
    if (!question.trim()) {
      setError("Please enter a DSA question first.");
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

  const askExample = (text) => {
    setQuestion(text);
    setAnswer("");
    setError("");
  };

  return (
    <div className="app">
      <div className="background-glow glow-one"></div>
      <div className="background-glow glow-two"></div>

      <nav className="navbar">
        <div className="brand">
          <div className="brand-icon">⚡</div>

          <div>
            <div className="brand-name">AlgoSphere</div>
            <div className="brand-subtitle">AI LAB</div>
          </div>
        </div>

        <div className="nav-badge">
          <span></span>
          AI DSA ASSISTANT
        </div>
      </nav>

      <main>
        <section className="hero">
          <div className="hero-badge">
            <span>✦</span>
            INTELLIGENT DSA LEARNING
          </div>

          <h1>
            Think.
            <br />
            <span>Code. Solve.</span>
          </h1>

          <p className="hero-description">
            Your AI-powered companion for mastering Data Structures &
            Algorithms. Ask questions, understand concepts and prepare for
            technical interviews.
          </p>

          <div className="ai-box">
            <div className="ai-box-top">
              <div className="ai-status">
                <div className="status-dot"></div>
                <span>AlgoSphere AI</span>
                <small>ONLINE</small>
              </div>

              <span className="model-label">GPT POWERED</span>
            </div>

            <textarea
              value={question}
              onChange={(e) => {
                setQuestion(e.target.value);
                setError("");
              }}
              onKeyDown={(e) => {
                if (e.key === "Enter" && !e.shiftKey) {
                  e.preventDefault();
                  askAI();
                }
              }}
              placeholder="Ask anything about DSA..."
            />

            <div className="ai-box-bottom">
              <span className="hint">
                Press <b>Enter</b> to ask · <b>Shift + Enter</b> for new line
              </span>

              <button
                className="ask-button"
                onClick={askAI}
                disabled={loading}
              >
                {loading ? (
                  <>
                    <span className="spinner"></span>
                    Thinking...
                  </>
                ) : (
                  <>
                    Ask AI <span>→</span>
                  </>
                )}
              </button>
            </div>
          </div>

          {error && <div className="error-box">{error}</div>}

          <div className="examples">
            <span>TRY ASKING</span>

            <button
              onClick={() =>
                askExample("Explain binary search with a C++ example")
              }
            >
              Binary Search
            </button>

            <button
              onClick={() =>
                askExample("Explain sliding window technique with example")
              }
            >
              Sliding Window
            </button>

            <button
              onClick={() => askExample("Explain time complexity of merge sort")}
            >
              Merge Sort
            </button>
          </div>
        </section>

        {answer && (
          <section className="answer-section">
            <div className="answer-header">
              <div className="answer-title">
                <div className="bot-icon">✦</div>

                <div>
                  <h2>AI Explanation</h2>
                  <p>Generated by AlgoSphere AI</p>
                </div>
              </div>

              <span className="answer-badge">AI RESPONSE</span>
            </div>

            <div className="answer-content">{answer}</div>
          </section>
        )}

        <section className="stats">
          <div>
            <strong>01</strong>
            <span>AI DSA ASSISTANT</span>
          </div>

          <div>
            <strong>∞</strong>
            <span>QUESTIONS TO EXPLORE</span>
          </div>

          <div>
            <strong>C++</strong>
            <span>INTERVIEW FOCUSED</span>
          </div>
        </section>

        <section className="topics-section">
          <div className="section-heading">
            <div>
              <span className="section-label">EXPLORE DSA</span>
              <h2>Build your fundamentals.</h2>
            </div>

            <p>
              Strengthen the concepts that matter most in coding interviews.
            </p>
          </div>

          <div className="topic-grid">
            {topics.map((topic) => (
              <div className="topic-card" key={topic.title}>
                <div className="topic-icon">{topic.icon}</div>

                <h3>{topic.title}</h3>

                <p>{topic.text}</p>

                <span className="topic-arrow">↗</span>
              </div>
            ))}
          </div>
        </section>

        <section className="cta">
          <div className="cta-glow"></div>

          <div className="cta-content">
            <span>READY TO LEVEL UP?</span>

            <h2>
              Turn problems into
              <br />
              <em>patterns.</em>
            </h2>

            <p>
              Practice smarter. Understand deeper. Solve better.
            </p>

            <button
              onClick={() => {
                window.scrollTo({
                  top: 0,
                  behavior: "smooth",
                });
              }}
            >
              Start Learning <span>→</span>
            </button>
          </div>
        </section>
      </main>

      <footer>
        <div className="footer-brand">
          <div className="brand-icon small">⚡</div>
          <span>AlgoSphere AI</span>
        </div>

        <p>DSA + AI Assistant</p>

        <span className="footer-copy">Built for developers.</span>
      </footer>
    </div>
  );
}

export default App;