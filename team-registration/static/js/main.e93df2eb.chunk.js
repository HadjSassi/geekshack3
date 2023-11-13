(this["webpackJsonpgeeks-teams"] = this["webpackJsonpgeeks-teams"] || []).push([[0], {
    37: function (e, t, a) {
    }, 39: function (e, t, a) {
    }, 71: function (e, t, a) {
        "use strict";
        a.r(t);
        var n = a(1), c = a.n(n), s = a(15), r = a.n(s), i = (a(37), a(16)), o = a.n(i), u = a(29), l = a(11), d = a(2),
            j = (a(39), a.p + "static/media/chart.8adefed0.png"), b = a(30), p = a(32), h = a(31), O = a.n(h), m = a(5),
            g = a.n(m), f = a(0);
        var x = function () {
            var e = Object(n.useState)([""]), t = Object(d.a)(e, 2), a = (t[0], t[1], Object(n.useState)(!1)),
                c = Object(d.a)(a, 2), s = c[0], r = c[1], i = Object(n.useState)(), h = Object(d.a)(i, 2), m = h[0],
                x = h[1], v = Object(n.useState)(!1), y = Object(d.a)(v, 2), w = (y[0], y[1]),
                S = Object(n.useState)(!1), k = Object(d.a)(S, 2), N = k[0], C = k[1], D = Object(n.useState)(""),
                T = Object(d.a)(D, 2), _ = T[0], F = T[1], L = Object(n.useState)(""), E = Object(d.a)(L, 2), M = E[0],
                A = E[1], R = Object(n.useState)(""), I = Object(d.a)(R, 2), P = I[0], z = I[1],
                B = Object(n.useState)(""), Y = Object(d.a)(B, 2), q = Y[0], J = Y[1], H = Object(n.useState)(""),
                U = Object(d.a)(H, 2), Z = U[0], G = U[1], K = Object(n.useState)(""), Q = Object(d.a)(K, 2),
                V = (Q[0], Q[1], Object(n.useState)("")), W = Object(d.a)(V, 2), X = W[0], $ = W[1],
                ee = Object(n.useState)("green"), te = Object(d.a)(ee, 2), ae = te[0], ne = te[1],
                ce = Object(n.useState)(""), se = Object(d.a)(ce, 2), re = se[0], ie = se[1],
                oe = Object(n.useState)(""), ue = Object(d.a)(oe, 2), le = ue[0], de = ue[1],
                je = Object(n.useState)(!0), be = Object(d.a)(je, 2), pe = be[0], he = be[1],
                Oe = Object(n.useState)(!0), me = Object(d.a)(Oe, 2), ge = me[0], fe = me[1],
                xe = Object(n.useState)(0), ve = Object(d.a)(xe, 2), ye = ve[0], we = ve[1], Se = Object(n.useState)(0),
                ke = Object(d.a)(Se, 2), Ne = ke[0], Ce = ke[1], De = Object(n.useState)(""), Te = Object(d.a)(De, 2),
                _e = Te[0], Fe = Te[1], Le = Object(n.useState)(""), Ee = Object(d.a)(Le, 2), Me = Ee[0], Ae = Ee[1],
                Re = Object(n.useState)([!1, !0, !0]), Ie = Object(d.a)(Re, 2), Pe = Ie[0], ze = Ie[1],
                Be = Object(n.useState)(""), Ye = Object(d.a)(Be, 2), qe = (Ye[0], Ye[1], function (e) {
                    var t = Object(l.a)(Pe);
                    t[e] = !0, t[e + 1] = !1, ze(t)
                }), Je = function (e) {
                    var t = Object(l.a)(Pe);
                    t[e] = !0, t[e - 1] = !1, ze(t)
                }, He = Object(n.useState)(!1), Ue = Object(d.a)(He, 2), Ze = Ue[0], Ge = Ue[1],
                Ke = Object(n.useState)(""), Qe = Object(d.a)(Ke, 2), Ve = Qe[0], We = Qe[1],
                Xe = Object(n.useState)(""), $e = Object(d.a)(Xe, 2), et = $e[0], tt = $e[1],
                at = Object(n.useState)(""), nt = Object(d.a)(at, 2), ct = nt[0], st = nt[1],
                rt = Object(n.useState)(""), it = Object(d.a)(rt, 2), ot = it[0], ut = it[1],
                lt = Object(n.useState)(""), dt = Object(d.a)(lt, 2), jt = dt[0], bt = dt[1],
                pt = Object(n.useState)(0), ht = Object(d.a)(pt, 2), Ot = ht[0], mt = ht[1],
                gt = Object(n.useRef)(null), ft = Object(n.useState)("00:00:00"), xt = Object(d.a)(ft, 2), vt = xt[0],
                yt = xt[1], wt = function (e) {
                    var t = function (e) {
                        var t = Date.parse(e) - Date.parse(new Date), a = Math.floor(t / 1e3 % 60),
                            n = Math.floor(t / 1e3 / 60 % 60);
                        return {total: t, hours: Math.floor(t / 1e3 * 60 * 60 % 24), minutes: n, seconds: a}
                    }(e), a = t.total, n = (t.hours, t.minutes), c = t.seconds;
                    a >= 0 && yt((n > 9 ? n : "0" + n) + ":" + (c > 9 ? c : "0" + c))
                }, St = function (e) {
                    yt("30:00"), gt.current && clearInterval(gt.current);
                    var t = setInterval((function () {
                        wt(e)
                    }), 1e3);
                    gt.current = t
                }, kt = function () {
                    var e = new Date;
                    return e.setSeconds(e.getSeconds() + 1800), e
                };
            return Object(n.useEffect)(Object(u.a)(o.a.mark((function e() {
                var t;
                return o.a.wrap((function (e) {
                    for (; ;) switch (e.prev = e.next) {
                        case 0:
                            return e.next = 2, g.a.get("https://geekshack.ensitgeeksclub.com/number.php");
                        case 2:
                            t = e.sent, mt(t.data), St(kt());
                        case 5:
                        case"end":
                            return e.stop()
                    }
                }), e)
            }))), []), "00:00" == vt && window.location.reload(), 1 == Ot ? Object(f.jsx)("div", {
                className: "screen",
                children: Object(f.jsxs)("div", {
                    className: "container",
                    style: {margin: "7% auto"},
                    children: [Object(f.jsx)("img", {src: j}), Object(f.jsx)("br", {}), Object(f.jsx)("br", {}), Object(f.jsx)("h1", {
                        style: {
                            textAlign: "center",
                            color: "red"
                        }, children: "Sorry the limit is reached !!!"
                    })]
                })
            }) : Object(f.jsx)("div", {
                className: "screen", children: Object(f.jsxs)("div", {
                    className: "container",
                    children: [Object(f.jsx)("img", {src: j}), Object(f.jsxs)(O.a, {
                        isOpen: N,
                        onAfterOpen: function () {
                            C(!0)
                        },
                        onRequestClose: function () {
                            C(!1), r(!1)
                        },
                        style: {
                            content: {
                                top: "50%",
                                left: "50%",
                                right: "auto",
                                bottom: "auto",
                                marginRight: "-50%",
                                transform: "translate(-50%, -50%)",
                                alignContent: "center",
                                borderRadius: "4%",
                                paddingTop: "0",
                                paddingBottom: "2%",
                                backgroundColor: q,
                                zIndex: 100
                            }
                        },
                        ariaHideApp: !1,
                        contentLabel: "Alert",
                        children: [Object(f.jsx)("h2", {
                            style: {color: P},
                            children: M
                        }), Object(f.jsx)("div", {
                            style: {margin: "0 auto", fontSize: "16px", color: "white"},
                            children: _
                        })]
                    }), Object(f.jsx)("form", {
                        onSubmit: function (e) {
                            if (e.preventDefault(), r(!0), "" !== Z && "" !== et && m) {
                                var t = new FormData;
                                t.append("team_tag", Z), t.append("leader_username", et), t.append("member_one_username", _e), t.append("member_two_username", Me), t.append("preuve", m), g.a.post("https://geekshack.ensitgeeksclub.com/paiement.php", t).then((function (e) {
                                    r(!1), 200 == e.status && (J("#41d888"), C(!0), F(e.data), z("white"), A("Success")), e.status >= 201 && (J("#f94416"), C(!0), F(e.data), z("white"), A("Error"))
                                })).catch((function (e) {
                                    J("#f94416"), C(!0), F("Server error"), z("white"), A("Error")
                                }))
                            } else J("#f94416"), C(!0), F("Please make sure to type all team informations !"), z("white"), A("Error")
                        }, children: Object(f.jsxs)("div", {
                            className: "row",
                            children: [Object(f.jsxs)("div", {
                                style: {margin: "0 auto", width: "100%"},
                                children: [Object(f.jsxs)("h2", {
                                    style: {textAlign: "center"},
                                    children: ["Team Registration Form", Object(f.jsx)("br", {})]
                                }), Object(f.jsxs)("h3", {
                                    style: {textAlign: "center", color: "#1c83d1"},
                                    children: [""]
                                })]
                            }), Object(f.jsxs)("div", {
                                hidden: Pe[0],
                                children: [Object(f.jsx)("input", {
                                    className: "input-group.input-group-icon",
                                    type: "text",
                                    placeholder: "Team name",
                                    name: "teamName",
                                    onChange: function (e) {
                                        !function (e) {
                                            if (/[^a-zA-Z0-9_]/.test(e.target.value)) $("Team tag must contain letters and numbers only !!"), ne("red"); else if (5 <= e.target.value.length && e.target.value.length <= 15) {
                                                G(e.target.value);
                                                var t = new FormData;
                                                t.append("team_tag", e.target.value), g.a.post("https://geekshack.ensitgeeksclub.com/teamname.php", t).then((function (e) {
                                                    r(!1), 200 == e.status && (he(!1), $(e.data), ne("green")), e.status >= 201 && ($(e.data), he(!0), ne("red"))
                                                })).catch((function (e) {
                                                    J("#f94416"), C(!0), F("Server error"), z("white"), A("Error")
                                                }))
                                            } else $("Team tag length must contain at least 5 characters !!"), ne("red")
                                        }(e)
                                    }
                                }), Object(f.jsx)("p", {
                                    style: {color: ae, paddingLeft: "1em"},
                                    children: X
                                }), Object(f.jsx)("input", {
                                    className: "input-group.input-group-icon",
                                    type: "text",
                                    placeholder: "Leader username",
                                    name: "leader",
                                    onChange: function (e) {
                                        !function (e) {
                                            tt(e.target.value);
                                            var t = new FormData;
                                            t.append("leader_username", e.target.value), g.a.post("https://geekshack.ensitgeeksclub.com/leader.php", t).then((function (e) {
                                                r(!1), 200 == e.status && (fe(!1), We(e.data), st("green")), e.status >= 201 && (We(e.data), fe(!0), st("red"))
                                            })).catch((function (e) {
                                                J("#f94416"), C(!0), F("Server error"), z("white"), A("Error")
                                            }))
                                        }(e)
                                    }
                                }), Object(f.jsx)("p", {
                                    style: {color: ct, paddingLeft: "1em"},
                                    children: Ve
                                }), Object(f.jsx)("input", {
                                    type: "button",
                                    value: "Next",
                                    className: "btn",
                                    onClick: function () {
                                        qe(0)
                                    },
                                    style: {padding: "5px", height: "40px", marginTop: "1%"},
                                    disabled: ge || pe
                                })]
                            }), Object(f.jsxs)("div", {
                                hidden: Pe[1],
                                children: [Object(f.jsx)("label", {
                                    className: "doc",
                                    style: {padding: "0", margin: "1%", marginTop: "0", display: "flex"},
                                    children: Object(f.jsx)("div", {
                                        style: {width: "90%"},
                                        children: Object(f.jsx)("input", {
                                            style: {margin: "0", border: "none"},
                                            type: "text",
                                            name: "Member_one",
                                            placeholder: "Member_one",
                                            onChange: function (e) {
                                                !function (e) {
                                                    if ("" != e.target.value) if (Fe(e.target.value), e.target.value == Me) de("Don't use the same username twice"), ut("red"), Ge(!0), we(0); else if (e.target.value != et) {
                                                        var t = new FormData;
                                                        t.append("username", e.target.value), g.a.post("https://geekshack.ensitgeeksclub.com/member.php", t).then((function (e) {
                                                            r(!1), 200 == e.status && (fe(!1), de(e.data), ut("green"), Ge(!1), we(20)), e.status >= 201 && (de(e.data), fe(!0), ut("red"), Ge(!0), we(0))
                                                        })).catch((function (e) {
                                                            J("#f94416"), C(!0), F("Server error"), z("white"), A("Error"), Ge(!0), we(0)
                                                        }))
                                                    } else ie("Not allowed to use leader username"), Ge(!0), we(0); else Fe(""), de(""), Ge(!1), we(0)
                                                }(e)
                                            }
                                        })
                                    })
                                }), Object(f.jsx)("p", {
                                    style: {color: ot, paddingLeft: "1em"},
                                    children: le
                                }), Object(f.jsx)("label", {
                                    className: "doc",
                                    style: {padding: "0", margin: "1%", marginTop: "0", display: "flex"},
                                    children: Object(f.jsx)("div", {
                                        style: {width: "90%"},
                                        children: Object(f.jsx)("input", {
                                            style: {margin: "0", border: "none"},
                                            type: "text",
                                            name: "Member_two",
                                            placeholder: "Member_two",
                                            onChange: function (e) {
                                                !function (e) {
                                                    if ("" != e.target.value) if (e.target.value == _e) ie("Don't use the same username twice"), bt("red"), Ge(!0), Ce(0); else if (e.target.value != et) {
                                                        Ae(e.target.value);
                                                        var t = new FormData;
                                                        t.append("username", e.target.value), g.a.post("https://geekshack.ensitgeeksclub.com/member.php", t).then((function (e) {
                                                            r(!1), 200 == e.status && (ie(e.data), bt("green"), Ge(!1), Ce(20)), e.status >= 201 && (ie(e.data), bt("red"), Ge(!0), Ce(0))
                                                        })).catch((function (e) {
                                                            J("#f94416"), C(!0), F("Server error"), z("white"), A("Error"), Ge(!0), Ce(0)
                                                        }))
                                                    } else ie("Not allowed to use leader username"), st("red"), Ge(!0), Ce(0); else Ae(""), ie(""), Ge(!1), Ce(0)
                                                }(e)
                                            }
                                        })
                                    })
                                }), Object(f.jsx)("p", {
                                    style: {color: jt, paddingLeft: "1em"},
                                    children: re
                                }), Object(f.jsxs)("div", {
                                    className: "btc",
                                    children: [Object(f.jsx)("p", {
                                        style: {color: "#1c83d1", paddingLeft: "1em"},
                                        children: Object(f.jsx)("strong", {children: "You can skip this step if you are a solo candidate !"})
                                    }), Object(f.jsx)("input", {
                                        type: "button",
                                        value: "Previous",
                                        className: "btn",
                                        onClick: function () {
                                            Je(1)
                                        },
                                        style: {padding: "5px", height: "40px", marginTop: "1%"}
                                    }), Object(f.jsx)("input", {
                                        type: "button",
                                        value: "Next",
                                        disabled: Ze,
                                        className: "btn",
                                        onClick: function () {
                                            qe(1)
                                        },
                                        style: {padding: "5px", height: "40px", marginTop: "1%"}
                                    })]
                                })]
                            }), Object(f.jsxs)("div", {
                                hidden: Pe[2],
                                children: [Object(f.jsx)("p", {
                                    style: {paddingLeft: "2%"},
                                    children: Object(f.jsx)("strong", {children: "*Make sure to provide us with a photo of your payment receipt"})
                                }), Object(f.jsxs)("p", {
                                    style: {paddingLeft: "2%", color: "#1c83d1"},
                                    children: ["*You have to pay ", Object(f.jsxs)("strong", {children: [20 + ye + Ne, " DT"]}), " by money transfer through ", Object(f.jsx)("strong", {children: "D17"}), " app ", Object(f.jsx)("strong", {children: "43308524"})]
                                }), Object(f.jsxs)("label", {
                                    className: "doc",
                                    children: [Object(f.jsx)(b.a, {
                                        icon: p.a,
                                        style: {paddingRight: "1%"}
                                    }), m ? m.name : "Upload your document", Object(f.jsx)("input", {
                                        className: "input-group.input-group-icon",
                                        hidden: !0,
                                        type: "file",
                                        placeholder: "preuve",
                                        name: "preuve",
                                        onChange: function (e) {
                                            x(e.target.files[0]), w(!0)
                                        }
                                    })]
                                }), Object(f.jsx)("br", {}), s ? Object(f.jsx)("div", {
                                    style: {margin: "0 auto"},
                                    className: "loader"
                                }) : Object(f.jsxs)(f.Fragment, {
                                    children: [Object(f.jsx)("input", {
                                        type: "button",
                                        value: "Previous",
                                        className: "btn",
                                        onClick: function () {
                                            Je(2)
                                        },
                                        style: {padding: "5px", height: "40px", marginTop: "1%"}
                                    }), Object(f.jsx)("input", {
                                        value: "Submit",
                                        type: "submit",
                                        className: "btn",
                                        style: {padding: "5px", height: "40px", marginTop: "1%"}
                                    })]
                                })]
                            })]
                        })
                    })]
                })
            })
        }, v = function (e) {
            e && e instanceof Function && a.e(3).then(a.bind(null, 72)).then((function (t) {
                var a = t.getCLS, n = t.getFID, c = t.getFCP, s = t.getLCP, r = t.getTTFB;
                a(e), n(e), c(e), s(e), r(e)
            }))
        };
        r.a.render(Object(f.jsx)(c.a.StrictMode, {children: Object(f.jsx)(x, {})}), document.getElementById("root")), v()
    }
}, [[71, 1, 2]]]);
//# sourceMappingURL=main.e93df2eb.chunk.js.map